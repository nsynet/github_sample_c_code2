#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <libgen.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024
#define CONFIG_FILE_NAME ".myconfig"

typedef struct ConfigEntry {
    char *key;
    char *value;
    struct ConfigEntry *next;
} ConfigEntry;

// 创建新的配置项
ConfigEntry* create_entry(const char *key, const char *value) {
    ConfigEntry *entry = malloc(sizeof(ConfigEntry));
    if (!entry) return NULL;
    
    entry->key = strdup(key);
    entry->value = strdup(value);
    entry->next = NULL;
    
    if (!entry->key || !entry->value) {
        free(entry->key);
        free(entry->value);
        free(entry);
        return NULL;
    }
    
    return entry;
}

// 释放配置链表
void free_config(ConfigEntry *head) {
    while (head) {
        ConfigEntry *next = head->next;
        free(head->key);
        free(head->value);
        free(head);
        head = next;
    }
}

// 添加配置项到链表
void add_entry(ConfigEntry **head, ConfigEntry *entry) {
    if (*head == NULL) {
        *head = entry;
        return;
    }
    
    ConfigEntry *current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = entry;
}

// 获取配置文件路径
char* get_config_path() {
    char *home = getenv("HOME");
    if (!home) {
        fprintf(stderr, "Error: HOME environment variable not set\n");
        return NULL;
    }
    
    char *path = malloc(strlen(home) + strlen(CONFIG_FILE_NAME) + 2);
    if (!path) return NULL;
    
    sprintf(path, "%s/%s", home, CONFIG_FILE_NAME);
    return path;
}

// 解析配置文件
ConfigEntry* parse_config(const char *path) {
    FILE *file = fopen(path, "r");
    if (!file) return NULL;
    
    ConfigEntry *head = NULL;
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        // 跳过注释行和空行
        if (line[0] == '#' || line[0] == '\n') continue;
        
        // 移除换行符
        line[strcspn(line, "\n")] = 0;
        
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "");
        
        if (key && value) {
            ConfigEntry *entry = create_entry(key, value);
            if (entry) {
                add_entry(&head, entry);
            }
        }
    }
    
    fclose(file);
    return head;
}

// 保存配置到文件
int save_config(const char *path, ConfigEntry *head) {
    FILE *file = fopen(path, "w");
    if (!file) {
        perror("Error opening config file for writing");
        return 0;
    }
    
    fprintf(file, "# My Application Configuration\n");
    fprintf(file, "# Auto-generated, do not edit manually\n\n");
    
    ConfigEntry *current = head;
    while (current) {
        fprintf(file, "%s=%s\n", current->key, current->value);
        current = current->next;
    }
    
    fclose(file);
    return 1;
}

// 获取配置值
const char* get_value(ConfigEntry *head, const char *key) {
    ConfigEntry *current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// 设置配置值
void set_value(ConfigEntry **head, const char *key, const char *value) {
    ConfigEntry *current = *head;
    
    // 检查键是否已存在
    while (current) {
        if (strcmp(current->key, key) == 0) {
            free(current->value);
            current->value = strdup(value);
            return;
        }
        current = current->next;
    }
    
    // 添加新条目
    ConfigEntry *new_entry = create_entry(key, value);
    if (new_entry) {
        add_entry(head, new_entry);
    }
}

// 删除配置项
void unset_value(ConfigEntry **head, const char *key) {
    ConfigEntry *current = *head;
    ConfigEntry *prev = NULL;
    
    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                *head = current->next;
            }
            free(current->key);
            free(current->value);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// 打印所有配置项
void list_config(ConfigEntry *head) {
    if (!head) {
        printf("No configuration entries found\n");
        return;
    }
    
    printf("Current configuration:\n");
    ConfigEntry *current = head;
    while (current) {
        printf("  %s = %s\n", current->key, current->value);
        current = current->next;
    }
}

// 打印使用说明
void print_usage(const char *prog_name) {
    printf("Usage: %s [options]\n", prog_name);
    printf("Options:\n");
    printf("  --get <key>      Get configuration value\n");
    printf("  --set <key> <value> Set configuration value\n");
    printf("  --unset <key>    Remove configuration entry\n");
    printf("  --list           List all configuration entries\n");
    printf("  --file <path>    Specify custom config file\n");
    printf("  --help           Show this help message\n");
}

int main(int argc, char *argv[]) {
    int opt_get = 0, opt_set = 0, opt_unset = 0, opt_list = 0, opt_help = 0;
    char *key = NULL, *value = NULL, *custom_file = NULL;
    
    struct option long_options[] = {
        {"get",   required_argument, 0, 'g'},
        {"set",   required_argument, 0, 's'},
        {"unset", required_argument, 0, 'u'},
        {"list",  no_argument,       0, 'l'},
        {"file",  required_argument, 0, 'f'},
        {"help",  no_argument,       0, 'h'},
        {0, 0, 0, 0}
    };
    
    int c;
    while ((c = getopt_long(argc, argv, "g:s:u:lf:h", long_options, NULL)) != -1) {
        switch (c) {
            case 'g':
                opt_get = 1;
                key = optarg;
                break;
            case 's':
                opt_set = 1;
                key = optarg;
                if (optind < argc && argv[optind][0] != '-') {
                    value = argv[optind];
                    optind++;
                } else {
                    fprintf(stderr, "Error: --set requires a value\n");
                    return 1;
                }
                break;
            case 'u':
                opt_unset = 1;
                key = optarg;
                break;
            case 'l':
                opt_list = 1;
                break;
            case 'f':
                custom_file = optarg;
                break;
            case 'h':
                opt_help = 1;
                break;
            default:
                return 1;
        }
    }
    
    if (opt_help) {
        print_usage(argv[0]);
        return 0;
    }
    
    // 获取配置文件路径
    char *config_path = custom_file ? custom_file : get_config_path();
    if (!config_path) return 1;
    
    // 加载配置
    ConfigEntry *config = parse_config(config_path);
    
    // 执行操作
    if (opt_get) {
        const char *val = get_value(config, key);
        if (val) {
            printf("%s\n", val);
        } else {
            printf("Key '%s' not found\n", key);
            return 1;
        }
    } 
    else if (opt_set) {
        set_value(&config, key, value);
        if (!save_config(config_path, config)) {
            return 1;
        }
    } 
    else if (opt_unset) {
        unset_value(&config, key);
        if (!save_config(config_path, config)) {
            return 1;
        }
    } 
    else if (opt_list) {
        list_config(config);
    } 
    else {
        print_usage(argv[0]);
    }
    
    // 清理资源
    free_config(config);
    if (!custom_file) free(config_path);
    
    return 0;
}