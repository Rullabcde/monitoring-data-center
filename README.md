# Monitoring Ruang Server Berbasis IoT

Proyek ini adalah sistem pemantauan suhu, kelembapan, dan parameter listrik (tegangan, arus, daya) untuk ruang server atau data center. Sistem ini menggunakan sensor **DHT11** dan **PZEM-004T** yang terhubung dengan NodeMCU ESP8266.

Data pemantauan dikirim ke platform **Blynk IoT**, memungkinkan pemantauan jarak jauh melalui aplikasi smartphone. Selain itu, sistem ini memberikan peringatan lokal melalui **Buzzer** dan **LED** jika parameter melebihi ambang batas yang ditentukan.

## Fitur Utama

  - **🌡️ Pemantauan Suhu & Kelembapan:** Mendeteksi suhu dan kelembapan ruangan secara *real-time* menggunakan sensor DHT11.
  - **⚡ Pemantauan Listrik:** Mengukur tegangan (V), arus (A), dan daya (W) menggunakan sensor PZEM-004T.
  - **📱 Dasbor IoT:** Visualisasi data secara langsung pada aplikasi Blynk.
  - **🚨 Sistem Peringatan:** Notifikasi instan melalui Buzzer dan LED jika terjadi anomali (misalnya, suhu terlalu tinggi).
  - **🔌 Berbasis ESP8266:** Menggunakan mikrokontroler NodeMCU yang populer dan mudah digunakan.

-----

## Kebutuhan Perangkat Keras

Untuk membangun proyek ini, Anda memerlukan komponen berikut:

1.  **NodeMCU ESP8266:** 1 unit
2.  **Sensor Suhu & Kelembapan:** DHT11
3.  **Sensor Energi Listrik:** PZEM-004T v3.0 (termasuk *Current Transformer* CT)
4.  **Indikator Peringatan:**
      - Buzzer Aktif (Active Buzzer)
      - LED (warna merah atau sesuai selera)
5.  **Resistor:** 220 Ohm (untuk LED)
6.  **Kabel Jumper**

### Skema Rangkaian

![Skema Rangkaian](Schematic.png)

## Kebutuhan Perangkat Lunak

1.  **[Arduino IDE](https://www.arduino.cc/en/software)**
2.  **Driver CP2102/CH340:** Sesuai dengan tipe NodeMCU Anda.
3.  **Blynk App:** Tersedia di [Google Play Store](https://www.google.com/search?q=https://play.google.com/store/apps/details%3Fid%3Dio.blynk) dan [Apple App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868).
4.  **Library Arduino:**
      - `Blynk`
      - `ESP8266WiFi`
      - `DHT`
      - `PZEM004Tv30`
      - `SimpleTimer`

-----

## Panduan Pengaturan

### 1\. Konfigurasi Blynk

1.  Buat akun di aplikasi **Blynk**.
2.  Buat **Proyek Baru** (*New Project*).
3.  Pilih perangkat keras **NodeMCU**.
4.  **Auth Token** akan dikirimkan ke email Anda. Simpan token ini.
5.  Tambahkan *widget* ke dasbor Anda:
      - **Gauge** untuk Suhu, Kelembapan, Tegangan, Arus, dan Daya.
      - **LED** untuk status peringatan.
      - Atur **Virtual Pin** untuk setiap *widget* sesuai dengan yang ada di kode.

### 2\. Pengaturan Arduino IDE

1.  Instal Arduino IDE dan atur *board* **ESP8266**.
2.  Buka **Library Manager** (`Sketch` \> `Include Library` \> `Manage Libraries...`).
3.  Cari dan instal semua *library* yang tercantum di atas.

### 3\. Unggah Kode

1.  Buka file `.ino` dari repositori ini di Arduino IDE.

2.  Ubah baris berikut dengan kredensial Anda:

    ```cpp
    // Masukkan Auth Token dari aplikasi Blynk Anda
    char auth[] = "YourBlynkAuthToken";

    // Masukkan detail WiFi Anda
    char ssid[] = "YourWiFi_SSID";
    char pass[] = "YourWiFi_Password";
    ```

3.  Pilih *board* **"NodeMCU 1.0 (ESP-12E Module)"** dan **Port** yang benar.

4.  Klik **Upload** untuk mengunggah kode ke NodeMCU.

-----

## Cara Penggunaan

1.  Pastikan semua komponen terhubung sesuai dengan skema rangkaian.
2.  Nyalakan perangkat.
3.  NodeMCU akan terhubung ke WiFi dan server Blynk.
4.  Buka aplikasi Blynk di smartphone Anda.
5.  Anda akan melihat data suhu, kelembapan, dan listrik ditampilkan secara *real-time* di dasbor.
6.  Jika suhu melebihi ambang batas yang ditentukan dalam kode, Buzzer akan berbunyi dan LED akan menyala sebagai peringatan.
