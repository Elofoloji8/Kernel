#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/time.h>
 
static unsigned long start_time; // Modül başlatılma zamanı
static int load_count = 0; // Modül yüklenme sayısı
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sizin İsminiz");
MODULE_DESCRIPTION("Basit bir Linux sürücü modülü");
MODULE_VERSION("0.1"); 
static int __init simple_driver_init(void) {
    load_count++; // Yüklenme sayısını artır
    start_time = jiffies; // Başlangıç zamanını al
    printk(KERN_INFO "Simple Driver: Başlatıldı! Yüklenme sayısı: %d\n", load_count);
 return 0;
}
  
static void __exit simple_driver_exit(void) {
    unsigned long elapsed_time = jiffies - start_time; // Geçen zamanı hesapla
    printk(KERN_INFO "Simple Driver: Kapatıldı! Çalışma süresi: %lu jiffies\n", elapsed_time);
 }
  
 module_init(simple_driver_init);
 module_exit(simple_driver_exit);
