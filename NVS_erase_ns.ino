#include <nvs.h> // Under development:DEV1

#define NS "localLog"
const char * _nvs_errors[13] = { "OTHER", "NOT_INITIALIZED", "NOT_FOUND", "TYPE_MISMATCH", "READ_ONLY", "NOT_ENOUGH_SPACE", "INVALID_NAME", "INVALID_HANDLE", "REMOVE_FAILED", "KEY_TOO_LONG", "PAGE_FULL", "INVALID_STATE", "INVALID_LENGHT"};
#define nvs_error(e) (((e)>ESP_ERR_NVS_BASE)?_nvs_errors[(e)&~(ESP_ERR_NVS_BASE)]:_nvs_errors[0])


void setup() {
  uint32_t nvsHandle; 
  Serial.begin(112500);
  Serial.printf("open %s ",NS);
  esp_err_t err = nvs_open(NS, NVS_READWRITE, &nvsHandle);
  if (!err) Serial.printf("OK\n");
  else {
    Serial.println(nvs_error(err)); 
    return;
  }
  Serial.printf("erase %s ",NS);
  err=nvs_erase_all(nvsHandle);
  if (!err) Serial.printf("OK\n");
  else {
    Serial.println(nvs_error(err)); 
    return;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
