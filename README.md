
🛸 Fullstack IoT Servo Controller 🕹️



"Bridging the gap between Web and Hardware." ⚡
Project ini adalah sistem kontrol servo Hybrid menggunakan Wemos D1 Mini (ESP8266). Kamu bisa menggerakkan servo secara presisi lewat dashboard web atau secara manual pakai tombol fisik. Sangat cocok buat portofolio IoT Fullstack Developer.

✨ Features Highlight
- 🎮 Dual-Control System: Kontrol via 2 Tombol Fisik (INC/DEC) & Input Digital via Web.

- 🔄 Real-time State Sync: Dashboard otomatis update posisi sudut setiap 1 detik tanpa refresh halaman.

- 📡 RESTful API Interface:

  - GET /getData ➔ Fetching current servo angle.

  - POST /postData ➔ Sending new angle via JSON payload.

- 📱 Responsive Dashboard: UI modern yang mulus di layar HP maupun Desktop.

📸 Schematic Diagram
Berikut adalah jalur pengkabelan yang saya rancang untuk project ini:

| Komponen | Pin Wemos | Warna Kabel | Peran |
| :--- | :--- | :--- | :--- |
| **Servo MG90S** | `5V` | 🔴 Merah | VCC Power |
| | `GND` | 🟤 Coklat | Ground |
| | `D2` | 🟡 Kuning | PWM Signal |
| **Button INC** | `D3` | 🟢 Hijau | Input Pull-up |
| | `GND` | ⚫ Hitam | Ground |
| **Button DEC** | `D4` | 🔵 Biru | Input Pull-up |
| | `GND` | ⚫ Hitam | Ground |


🛠️ Tech Stack & Libraries
- Firmware: C++ (Arduino Core)

- Library: ArduinoJson v7 (Efficient JSON Parsing), Servo.h, ESP8266WebServer.

- Tooling: PlatformIO (VS Code).

- Frontend: HTML5, Modern CSS3 (Glassmorphism & Flexbox), Vanilla JS (Async/Await).


⚙️ Quick Start
- Clone repo ini ke PC kamu.

- Buka via VS Code (Pastikan extension PlatformIO sudah aktif).

- Edit main.cpp: Masukkan SSID & Password WiFi kamu.

- Flash firmware ke Wemos D1 Mini.

- Cek Serial Monitor untuk dapet IP Address (Contoh: 192.168.1.10).

- Edit script.js: Update variabel const IPWemos = "IP_KAMU".

- Open index.html and Let's Play! 🚀
    
🚀 Future Improvements
- [ ] Implementasi WebSocket untuk kontrol yang benar-benar instant (Zero Latency).

- [ ] Menambahkan Slider UI untuk kontrol sudut yang lebih fleksibel.

- [ ] Fitur Auto-Sweep mode dari Web.


CREATED BY WILLEA 🤖

