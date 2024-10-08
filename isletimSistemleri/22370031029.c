#include <linux/init.h>   // Mod�l giri�/��k�� fonksiyonlar� i�in
#include <linux/module.h> // Gerekli mod�l tan�mlamalar�
#include <linux/kernel.h> // KERNEL_INFO mesajlar� i�in

// Lisans, yazar, a��klama bilgileri
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Elif Buse �zt�rk");
MODULE_DESCRIPTION("Basit bir Hello World Kernel Mod�l�");
MODULE_VERSION("1.0");

// Mod�l y�klendi�inde �al��acak fonksiyon
static int __init hello_init(void) {
    printk(KERN_INFO "Hello, Kernel World!\n");
    return 0; // Ba�ar�l� y�kleme
}

// Mod�l kald�r�ld���nda �al��acak fonksiyon
static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, Kernel World!\n");
}

// Mod�l giri�/��k�� fonksiyonlar�n� tan�mla
module_init(hello_init);
module_exit(hello_exit);