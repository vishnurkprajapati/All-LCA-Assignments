
#include <stdio.h>
#include <string.h>

struct Device {
  int id;
  char type[10];
  float vf;
  float ir;
  float vr;
  char status[6];
};

struct Device create_device(int i) {

  struct Device device;

  printf("Enter details for device %d:\n", i + 1);

  printf("Device ID: ");
  scanf("%d", &device.id);

  printf("Device Type: ");
  scanf("%9s", device.type);

  printf("Forward voltage Vf (V): ");
  scanf("%f", &device.vf);

  printf("Reverse leakage current (milli amp): ");
  scanf("%f", &device.ir);

  printf("Rated voltage (V): ");
  scanf("%f", &device.vr);

  return device;
}

struct Device verify_device(struct Device device) {

  if (strcmp(device.type, "BJT") == 0) {
    float max_vf = 0.9;
    float max_ir = 10;
    float max_vr = 40;

    if (device.vf <= max_vf && device.ir <= max_ir && device.vr <= max_vr) {
      strcpy(device.status, "PASS");
    } else {
      strcpy(device.status, "FAIL");
    }
  }

  else if (strcmp(device.type, "Diode") == 0) {
    float max_vf = 0.8;
    float max_ir = 5;
    float max_vr = 50;

    if (device.vf <= max_vf && device.ir <= max_ir && device.vr <= max_vr) {
      strcpy(device.status, "PASS");
    } else {
      strcpy(device.status, "FAIL");
    }
  }

  else if (strcmp(device.type, "MOSFET") == 0) {
    float max_vf = 4.0;
    float max_ir = 1;
    float max_vr = 60;

    if (device.vf <= max_vf && device.ir <= max_ir && device.vr <= max_vr) {
      strcpy(device.status, "PASS");
    } else {
      strcpy(device.status, "FAIL");
    }
  }

  else if (strcmp(device.type, "LED") == 0) {
    float max_vf = 3.6;
    float max_ir = 10;
    float max_vr = 5;

    if (device.vf <= max_vf && device.ir <= max_ir && device.vr <= max_vr) {
      strcpy(device.status, "PASS");
    } else {
      strcpy(device.status, "FAIL");
    }
  }

  else {
    strcpy(device.status, "FAIL");
  }

  return device;
}

void print_status(struct Device device) {

  printf("\nDevice type: %s\n", device.type);
  printf("Device ID: %d\n", device.id);
  printf("Status: %s\n", device.status);
}

int main() {

  int n, i, j, k;
  struct Device device_list[100];

  printf("Enter the number of devices: ");
  scanf("%d", &n);

  if (n < 1 || n > 100) {
    printf("Invalid number of devices.\n");
    return 1;
  }

  for (i = 0; i < n; i++) {
    device_list[i] = create_device(i);
  }

  for (i = 0; i < n; i++) {
    device_list[i] = verify_device(device_list[i]);
  }

  for (i = 0; i < n; i++) {
    print_status(device_list[i]);
  }

  j = 0;

  for (i = 0; i < n; i++) {
    if (strcmp(device_list[i].status, "FAIL") == 0) {
      j++;
    }
  }

  printf("\nNumber of failed devices: %d\n", j);

  return 0;
}
