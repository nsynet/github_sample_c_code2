[toc]



| 功能  |创建   |销毁| 备注 | 参考代码 |
| ------------ | ------------ | ------------ | ------------ |------------ |
|~~注册字符设备(古老,不建议用)~~   | ~~register_chrdev()~~|unregister_chrdev()|register_chrdev()根据给定的主设备号是否为0来决定使用静态注册还是动态注册。当您使用unregister_chrdev()注销一个设备时，它会自动删除与该设备关联的cdev结构。但是，如果您使用unregister_chrdev_region()，您需要确保手动删除任何与该设备范围关联的cdev结构（如果有的话）| |
|~~注册字符设备(静态注册)~~|~~register_chrdev_region()~~   |unregister_chrdev_region()|register_chrdev_region() 是用于静态注册设备号的函数。它要求开发者指定设备的主设备号和次设备号的范围，并事先知道要使用的主、次设备号。在调用这个函数之前，开发者需要查看 /proc/devices 文件来确认哪些设备号没有被使用,比register_chrdev()繁琐,但是避免了 register_chrdev() 中可能导致的资源浪费问题。| |
|注册字符设备(动态注册)   | <p>alloc_chrdev_region() 分配一个设备号范围<br>cdev_alloc()<br>cdev_init()<br>cdev_add()<br></p>|cdev_del() + kfree() + unregister_chrdev_region()|register_chrdev_region（）函数用于已知起始设备的设备号的情况，而alloc_chrdev_region（）用于设备号未知，向系统动态申请未被占用的设备号的情况;需要在用户态执行mknod()生成设备节点 |<p>`https://github.com/nsynet/github_sample_c_code2/blob/main/_linux_driver_sample/Linux%E8%AE%BE%E5%A4%87%E9%A9%B1%E5%8A%A8%E5%BC%80%E5%8F%91%E8%AF%A6%E8%A7%A3%EF%BC%9A%E5%9F%BA%E4%BA%8E%E6%9C%80%E6%96%B0%E7%9A%84Linux4.0%E5%86%85%E6%A0%B8_%E5%AE%8B%E5%AE%9D%E5%8D%8E/develop/training/kernel/drivers/globalmem/ch6/globalmem_nisy.c`<br></p> |
|创建/sys/kernel/下的 kobject（Kernel Object）  |kobject_create_and_add()   |kobject_put   | <p>msm_cam_sysfs_kobj = kobject_create_and_add("camera_360", kernel_kobj);<br>msm_sensor_sysfs_add_link(msm_cam_sysfs_kobj, &s_ctrl->pdev->dev.kobj, "max9286_pid_all", "max9286_pid_all");<br>效果: /sys/kernel/camera_360/max9286_pid_all 指向 /sys/devices/soc/1b0c000.qcom,cci/1b0c000.qcom,cci:qcom,camera@1/max9286_pid_all</p> ||
|创建/sys/class/xxx 节点  | class_create()  |class_destroy()| |
|创建设备节点/dev/xxx   |device_create() 用于创建和注册设备实例  |device_destroy() | |
|创建/sys/xxx 文件节点   |<p>device_create_file（）用于在sysfs中创建设备属性文件<br>   sysfs_create_group()   </p>| sysfs_remove_group() | https://github.com/figozhang/runninglinuxkernel_5.0/tree/rlk_5.0/kmodules/rlk_lab/rlk_basic/chapter_12_debug/lab4_sysfs |  |
|创建procfs,即/proc/driver/xxx 节点   |proc_create_data()   |remove_proc_entry()| |
|创建procfs,即/proc/driver/xxx 节点   | proc_create()  |remove_proc_entry()|proc_create是 proc_create_data 的一个简化版本，它允许你创建一个 proc 文件，但不允许你传递一个自定义的数据指针给文件 | https://github.com/figozhang/runninglinuxkernel_5.0/tree/rlk_5.0/kmodules/rlk_lab/rlk_basic/chapter_12_debug/lab3_procfs|
| 中断的申请  | <p>gpio_is_valid(g_cam_gpio_status.cam_avm_lock_status);<br>gpio_request();<br>gpio_direction_input();<br>cam_avm_lock_irq = gpio_to_irq(g_cam_gpio_status.cam_avm_lock_status);<br>request_threaded_irq(cam_avm_lock_irq, NULL,cam_avm_lock_on_isr, irq_flags, "avm_lock_status", NULL); </p>|<p>/* 1. 禁用中断，确保不会有新的处理程序被调用,这一步是必须的! */<br>disable_irq_nosync(irq_num);<br>/* 2. 释放中断处理函数 (在disable之后，这里很安全) */<br>free_irq(irq_num, my_dev_id);<br>/* 3. 释放GPIO引脚 */<br>gpio_free(gpio_num);<br></p> | request_irq()是旧的接口| |
| GPIO输入  | <p>gpio_request()<br>gpio_direction_input()<br>gpio_get_value() </p> |gpio_free() |devm_gpio_request_one是gpio_request_one的设备管理版本。它在设备管理的上下文中申请GPIO，会自动管理GPIO的生命周期。当设备被移除或卸载时，它会自动释放所申请的GPIO，无需显式调用gpio_free。这使得代码更加简洁和可靠，因为不需要担心在设备卸载时忘记释放GPIO。另外，devm_gpio_request_one和gpio_request_one都允许在申请GPIO时设置其方向和初始值。例如，你可以使用devm_gpio_request_one将GPIO设置为输入或输出，并设置其初始电平为高电平或低电平。| |
| GPIO输出  | <p>gpio_request()<br>gpio_direction_output()<br>gpio_set_value()  </p>|gpio_free()| |
| GPIO编号转换为相应的IRQ（中断请求）编号  | gpio_to_irq()  | |如果GPIO引脚被配置为中断源，则此函数可以将GPIO编号转换为相应的IRQ（中断请求）编号。| |
|将IRQ编号转换为相应的GPIO编号   | irq_to_gpio()  | | | |
|供电芯片的开关   |<p>regulator_get();<br>regulator_enable();<br> regulator_disable();<br></p>  |regulator_put()| | |
|模块化的平台设备驱动   | module_platform_driver  | | | |
|非模块化的平台设备驱动   |<p>module_init时使用platform_driver_register()<br>probe时使用platform_set_drvdata()<br>of_platform_populate() 函数是一个用于从设备树（Device Tree）中解析并创建平台设备（platform devices）<br></p>|module_exit时使用platform_driver_unregister| | | |
|misc device注册   | misc_register()  |misc_deregister()  | misc_register()会自动创建文件节点,不需要mknod()手工创建设备节点（对比字符设备需要！）,misc设备不需要probe | https://github.com/figozhang/runninglinuxkernel_5.0/tree/rlk_5.0/kmodules/rlk_lab/rlk_basic/chapter_6_device_driver/lab2_misc_driver|
|i2c设备   |i2c_add_driver()   | i2c_del_driver()  | probe()阶段初始化:i2c_check_functionality()+i2c_set_clientdata() | |
|kernel module 的C代码和makefile参考   |   |  |  |https://github.com/figozhang/runninglinuxkernel_5.0/tree/rlk_5.0/kmodules/rlk_lab/rlk_basic/chapter_12_debug/lab3_procfs|
|module的加载和卸载   | insmod,但是推荐modprobe加载ko  | rmmod 卸载ko | lsmod查询ko |  |
|   |   |  |  |  |
|   |   |  |  |  |
|media设备   | <p>media_device_init()<br>media_device_register()<br>media_entity_pads_init()<br></p>|  |  | |
|v4l2设备   |<p>v4l2_device_register()<br>video_register_device()<br></p>   |  |  | |
|v4l2 subdevice设备   |<p>v4l2_subdev_init()<br>v4l2_device_register_subdev()</p>    |  |  | |
|workqueue   |<p>struct delayed_work i2c8_cam_periodic_check_wq={0};<br>void i2c8_cam_periodic_check_report_wq_routine(struct work_struct *data);<br>INIT_DELAYED_WORK(&i2c8_cam_periodic_check_wq ,    i2c8_cam_periodic_check_report_wq_routine);</p>| schedule_delayed_work(&i2c8_cam_periodic_check_wq, msecs_to_jiffies(200)); |  | |

复位处理:硬复位一般重新上电没有问题;但是软复位需要考虑外设的复位,否则可能有故障(比如外设配置了新地址,cpu仍然使用默认地址读写外设,导致找不到外设),需要做到reset键把必要的外设芯片都重启了,避免外设芯片一直上电,导致故障时reset后仍然有故障(类似摄像头的寄存器配置错误的故障)

----
devm_kzalloc()

devm_clk_get

devm_gpio_request_one

sysfs_create_group(struct kobject *kobj,const struct attribute_group *grp)

## 常用的内核函数
| 名称 | 用途 |
| ------------ | ------------ |
|debugfs_create_dir() |创建在/sys/kernel/debug/下的调试文件系统  | 

## 常用的内核开关
| 名称 | 用途 | 哪些开发板是开启的? |
| ------------ | ------------ | ------------ |
|CONFIG_DYNAMIC_DEBUG |CONFIG_DYNAMIC_DEBUG是一个用于动态调试的配置选项。当这个选项被启用（设置为y）时，内核会在编译阶段保留所有动态调试的语句。这些调试语句可以在运行时根据需要打开或关闭，通过特定的debugfs控制文件/sys/kernel/debug/dynamic_debug/control进行操作。这使得开发者能够灵活地选择需要调试的模块、文件、行号和格式，获取更为详细和针对性的调试信息。这对于解决复杂的内核问题或优化性能非常有帮助。  |  |
|CONFIG_COMPAT | 它主要用于支持32位应用在64位系统上运行。启用此选项可以确保内核提供必要的兼容层，使得旧版本的32位应用能够在新版本的64位系统上正常工作。这对于维护系统的向后兼容性非常重要，特别是在那些需要支持旧有软件或库的系统环境中。 |美格MEIG 6125开发板  |
| | |
| | |
| | |
| | |



## 排查内存问题
```
cat /proc/meminfo
cat /proc/zoneinfo
cat /proc/sys/vm/lowmem_reserve_ratio
cat /proc/buddyinfo
top -o %MEM
```



### 一个Linux内核模块的通用模板通常包括以下部分：

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
//每个module_init()都会被执行,但是在其init结构体中配置了 `of_match_table`,只有设备树中匹配上的,才能执行这个设备的probe函数.

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
