# Sistem Keamanan dengan Sensor PIR

Proyek ini akan mendeteksi adanya gerakan di sebuah ruangan menggunakan sensor PIR. Jika gerakan terdeteksi, Anda akan menerima notifikasi pada aplikasi Blynk.

## Kebutuhan Hardware

-   ESP32
-   Sensor PIR (Passive Infrared)
-   Breadboard dan Kabel Jumper

## Koneksi

-   **Sensor PIR:**
    -   Pin `VCC` -> 5V ESP32 (beberapa sensor PIR membutuhkan 5V)
    -   Pin `GND` -> GND ESP32
    -   Pin `OUT` -> **GPIO 27** ESP32

## Cara Penggunaan

1.  **Setup Software:**
    -   Install library `Blynk` dari Arduino IDE Library Manager.

2.  **Setup Blynk:**
    -   Buat project baru di aplikasi Blynk, pilih device ESP32.
    -   Salin `Auth Token`.
    -   **PENTING:** Di dashboard Blynk, buka tab `Events` dan buat event baru dengan nama `motion_detected`. Ini diperlukan agar notifikasi bisa dikirim.

3.  **Upload Kode:**
    -   Buka file `pir_security_alert.ino`.
    -   Ganti kredensial WiFi dan Blynk Auth Token.
    -   Upload kode ke ESP32.

4.  **Jalankan:**
    -   Buka Serial Monitor untuk melihat status.
    -   Arahkan sensor PIR ke area yang ingin dipantau.
    -   Saat ada gerakan, notifikasi akan muncul di ponsel Anda.
