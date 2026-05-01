#include <WiFi.h>
#include <HTTPClient.h>
#include <FS.h>
#include <SD.h>

class LanguageInstaller {
public:
    // ฟังก์ชันดาวน์โหลดแพ็กเกจภาษาใหม่ (1 ใน 190+ ภาษา)
    bool downloadLanguagePack(String langCode) {
        HTTPClient http;
        String url = "https://api.spring-sg.com/v1/languages/" + langCode + ".pkg";
        
        http.begin(url);
        int httpCode = http.GET();
        
        if (httpCode == HTTP_CODE_OK) {
            File file = SD.open("/languages/" + langCode + ".db", FILE_WRITE);
            http.writeToStream(&file);
            file.close();
            Serial.println("Language " + langCode + " installed successfully!");
            return true;
        }
        return false;
    }
};
