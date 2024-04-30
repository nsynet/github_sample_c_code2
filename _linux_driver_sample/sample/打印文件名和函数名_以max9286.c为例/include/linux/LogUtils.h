/***********************************************************************
* Filename: LogUtils.h
* Author: zhangjinqiang@dfmc.com.cn
* Description: Define different printing interface functions to unify
* log printing specifications
* Date：2020/12/26
* Version: 1230
* History: v0.1
*-----------------------------------------------------------------------
* Version     date          author                      description
* V0.1      ${12/26}     ${zhangjinqiang}      Add print control interface
* V0.2      ${21/01/12}  ${wuwp}               Add print control interface
*************************************************************************/

#ifndef _LOG_UTILS_H_
#define _LOG_UTILS_H_

#include <linux/printk.h>
#include <linux/string.h>
#include <linux/device.h>

#ifndef pr_fmt
#define pr_fmt(fmt) fmt
#endif // !pr_fmt

#define __FILENAME__ (strrchr(__FILE__, '/') + 1)

/* system is unusable, Usually not used */
#define LOGD_EMERG(fmt, ...) \
    printk(KERN_EMERG "[%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__,\
                        ##__VA_ARGS__)
/* action must be taken immediately， Usually not used */
#define LOGD_ALERT(fmt, ...) \
    printk(KERN_ALERT "[%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__,\
                        ##__VA_ARGS__)
/* critical conditions， Usually not used */
#define LOGD_CRIT(fmt, ...) \
    printk(KERN_CRIT "[%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__,\
                        ##__VA_ARGS__)
/* warning conditions */
#define LOGD_WARNING(fmt, ...) \
    printk(KERN_WARNING "[%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__,\
                        ##__VA_ARGS__)
/* normal but significant condition */
#define LOGD_NOTICE(fmt, ...) \
    printk(KERN_NOTICE "[%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__,\
                        ##__VA_ARGS__)

/* In G59 project, we use ERR, INFO and DEBUG print to save logs in different conditions */
/* error conditions */
#define LOGD_ERR(fmt, ...) \
    printk(KERN_ERR "[%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__,\
                        ##__VA_ARGS__)
/* informational */
#define LOGD_INFO(fmt, ...) \
    printk(KERN_INFO "[%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__,\
                        ##__VA_ARGS__)
/* debug-level messages */
#define LOGD_DEBUG(fmt, ...) \
    printk(KERN_DEBUG "[%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__, \
                        ##__VA_ARGS__)

/*If we need to know which device the print information corresponds to, please use the following macro to print*/
/*info level messages*/
#define DEV_LOGD_INFO(dev, fmt, ...) \
    printk(KERN_INFO "[%s][%s][%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__, \
                      dev_driver_string(dev), dev_name(dev), \
                      ##__VA_ARGS__)
/*error level messages*/
#define DEV_LOGD_ERR(dev, fmt, ...) \
    printk(KERN_ERR "[%s][%s][%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__, \
                      dev_driver_string(dev), dev_name(dev), \
                      ##__VA_ARGS__)
/*debug level messages*/
#define DEV_LOGD_DEBUG(dev, fmt, ...) \
    printk(KERN_DEBUG "[%s][%s][%s][%s]: " pr_fmt(fmt) "\n", __FILENAME__, __FUNCTION__, \
                      dev_driver_string(dev), dev_name(dev), \
                      ##__VA_ARGS__)

#endif
