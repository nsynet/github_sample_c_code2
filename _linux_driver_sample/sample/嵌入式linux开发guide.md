[toc]



| 功能  |创建   |销毁| 备注 |
| ------------ | ------------ | ------------ | ------------ |
|注册字符设备(古老,不建议用)   | register_chrdev()|unregister_chrdev()|register_chrdev()根据给定的主设备号是否为0来决定使用静态注册还是动态注册。当您使用unregister_chrdev()注销一个设备时，它会自动删除与该设备关联的cdev结构。但是，如果您使用unregister_chrdev_region()，您需要确保手动删除任何与该设备范围关联的cdev结构（如果有的话）|
|注册字符设备(静态注册)|register_chrdev_region()   |unregister_chrdev_region()|register_chrdev_region() 是用于静态注册设备号的函数。它要求开发者指定设备的主设备号和次设备号的范围，并事先知道要使用的主、次设备号。在调用这个函数之前，开发者需要查看 /proc/devices 文件来确认哪些设备号没有被使用,比register_chrdev()繁琐,但是避免了 register_chrdev() 中可能导致的资源浪费问题。|
|注册字符设备(动态注册)   | alloc_chrdev_region() 分配一个设备号范围+cdev_alloc()+cdev_init()+cdev_add()    |cdev_del() + kfree() + unregister_chrdev_region()|
|创建/sys/class/xxx 节点  | class_create()  |class_destroy()|
|创建设备节点/dev/xxx   |device_create()   |device_destroy() |
|创建sysfs,即/sys/devices/xxx 节点   | sysfs_create_group()  |sysfs_remove_group|
|创建procfs,即/proc/driver/xxx 节点   |proc_create_data()   |remove_proc_entry()|
|创建procfs,即/proc/driver/xxx 节点   | proc_create()  |remove_proc_entry()|proc_create是 proc_create_data 的一个简化版本，它允许你创建一个 proc 文件，但不允许你传递一个自定义的数据指针给文件 |
| 中断的申请  | <p>gpio_is_valid(g_cam_gpio_status.cam_avm_lock_status);<br>cam_avm_lock_irq = gpio_to_irq(g_cam_gpio_status.cam_avm_lock_status);<br>request_threaded_irq(cam_avm_lock_irq, NULL,cam_avm_lock_on_isr, irq_flags, "avm_lock_status", NULL); </p>| |
| GPIO输入  | <p>gpio_request()<br>gpio_direction_input()<br>gpio_get_value() </p> |gpio_free() |devm_gpio_request_one是gpio_request_one的设备管理版本。它在设备管理的上下文中申请GPIO，会自动管理GPIO的生命周期。当设备被移除或卸载时，它会自动释放所申请的GPIO，无需显式调用gpio_free。这使得代码更加简洁和可靠，因为不需要担心在设备卸载时忘记释放GPIO。另外，devm_gpio_request_one和gpio_request_one都允许在申请GPIO时设置其方向和初始值。例如，你可以使用devm_gpio_request_one将GPIO设置为输入或输出，并设置其初始电平为高电平或低电平。|
| GPIO输出  | <p>gpio_request()<br>gpio_direction_output()<br>gpio_set_value()  </p>|gpio_free()|
| GPIO编号转换为相应的IRQ（中断请求）编号  | gpio_to_irq()  ||如果GPIO引脚被配置为中断源，则此函数可以将GPIO编号转换为相应的IRQ（中断请求）编号。|
|将IRQ编号转换为相应的GPIO编号   | irq_to_gpio()  | |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |

复位处理:硬复位一般重新上电没有问题;但是软复位需要考虑外设的复位,否则可能有故障(比如外设配置了新地址,cpu仍然使用默认地址读写外设,导致找不到外设),需要做到reset键把必要的外设芯片都重启了,避免外设芯片一直上电,导致故障时reset后仍然有故障(类似摄像头的寄存器配置错误的故障)

----
devm_kzalloc()
devm_clk_get
devm_gpio_request_one
sysfs_create_group(struct kobject *kobj,const struct attribute_group *grp)


## 排查内存问题
```
cat /proc/meminfo
cat /proc/zoneinfo
cat /proc/sys/vm/lowmem_reserve_ratio
cat /proc/buddyinfo
top -o %MEM
```



###一个Linux内核模块的通用模板通常包括以下部分：

头文档：在模块的开头，通常包含必要的头文档，例如#include <linux/module.h>和#include <linux/kernel.h>等。
模块定义：使用module_LICENSE("GPL")宏声明模块的许可证，例如GPL。
模块参数：使用module_param宏定义模块参数，例如module_param(param_name, param_type, perm_attr)。其中，param_name是参数名称，param_type是参数类型，perm_attr是参数的访问权限。
模块导出函数：使用module_init(init_func)和module_exit(exit_func)宏定义模块的初始化和退出函数。其中，init_func是模块初始化函数，exit_func是模块退出函数。
模块描述：使用MODULE_DESCRIPTION(description)宏声明模块的描述信息。
模块参数列表：使用__param宏定义模块参数列表，例如__param(param_name, param_type)。
模块导出符号：使用EXPORT_SYMBOL(symbol)宏导出内核符号，例如EXPORT_SYMBOL(my_function)。
结束符号：使用MODULE_LICENSE("GPL")宏结束模块许可证声明。
以下是一个简单的Linux内核模块的通用模板示例：

```c
#include <linux/module.h>  
#include <linux/kernel.h>  
  
MODULE_LICENSE("GPL");  
  
MODULE_DESCRIPTION("My Module");  
  
module_param(param_name, param_type, perm_attr);  
  
__param(another_param, another_type);  
  
EXPORT_SYMBOL(my_function);  
  
static int __init my_module_init(void) {  
    // Initialization code here  
    return 0;  
}  
  
static void __exit my_module_exit(void) {  
    // Exit code here  
}  
  
module_init(my_module_init);  
module_exit(my_module_exit);
```

###
分析Linux内核执行时间过长的原因可以涉及多个方面。以下是一些常见的分析和调试步骤：

查看系统负载和性能指标：使用top、htop、vmstat、iostat等命令查看系统的CPU使用率、内存使用情况、磁盘IO等，以了解是否存在资源瓶颈。
检查进程状态和日志：使用ps、top等命令查看进程状态，并检查相关日志以确定是否有某个进程或线程占用了过多的CPU时间。
检查CPU占用情况：使用perf、top等工具检查CPU占用情况，找出最耗时的内核函数或线程。
分析系统调用：使用strace等工具跟踪进程的系统调用，以了解其在执行期间进行了哪些操作。
检查内核配置：检查内核配置文档（如/boot/config-*）以确定是否启用了某些可能影响性能的选项。
分析内核模块：检查加载的内核模块以及相关的配置，确定是否有某个模块导致了性能问题。
检查硬件问题：如果可能，检查硬件（如CPU、内存、磁盘等）是否存在问题或故障，以排除硬件故障导致的性能问题。
查看内核日志：检查内核日志（通常位于/var/log/messages或/var/log/kern.log）以查找与性能问题相关的错误消息或警告。
使用性能剖析工具：使用如perf, gprof, valgrind等性能剖析工具来深入分析内核函数的执行时间。
检查调度策略：检查系统的调度策略（如CPU亲和性、优先级等）是否合理，并确保系统没有过度调度或饥饿现象。
请注意，分析内核执行时间过长的原因可能涉及复杂的调试过程，并且结果可能因系统配置和特定工作负载而异。在进行更改之前，建议备份重要数据并谨慎操作。