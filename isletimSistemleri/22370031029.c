#include <linux/init.h>   // Modül giriþ/çýkýþ fonksiyonlarý için
#include <linux/module.h> // Gerekli modül tanýmlamalarý
#include <linux/kernel.h> // KERNEL_INFO mesajlarý için

// Lisans, yazar, açýklama bilgileri
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Elif Buse Öztürk");
MODULE_DESCRIPTION("Basit bir Hello World Kernel Modülü");
MODULE_VERSION("1.0");

// Modül yüklendiðinde çalýþacak fonksiyon
static int __init hello_init(void) {
    printk(KERN_INFO "Hello, Kernel World!\n");
    return 0; // Baþarýlý yükleme
}

// Modül kaldýrýldýðýnda çalýþacak fonksiyon
static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, Kernel World!\n");
}

// Modül giriþ/çýkýþ fonksiyonlarýný tanýmla
module_init(hello_init);
module_exit(hello_exit);