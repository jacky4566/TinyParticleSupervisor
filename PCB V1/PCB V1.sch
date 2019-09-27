EESchema Schematic File Version 4
LIBS:PCB V1-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR0102
U 1 1 5CC38EBC
P 2000 1700
F 0 "#PWR0102" H 2000 1450 50  0001 C CNN
F 1 "GND" V 2005 1572 50  0000 R CNN
F 2 "" H 2000 1700 50  0001 C CNN
F 3 "" H 2000 1700 50  0001 C CNN
	1    2000 1700
	0    1    1    0   
$EndComp
Text GLabel 3300 1800 2    50   Input ~ 0
LiPo+
Text GLabel 4075 1900 2    50   Input ~ 0
BoronEN
Text GLabel 3300 2800 2    50   Input ~ 0
SCL
Text GLabel 3300 2900 2    50   Input ~ 0
SDA
Text GLabel 1850 4475 0    50   Input ~ 0
SCL
$Comp
L Device:R_Small R2
U 1 1 5D90AA56
P 4050 2950
F 0 "R2" H 3925 2900 50  0000 C CNN
F 1 "4.7k" H 3900 2975 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4050 2950 50  0001 C CNN
F 3 "~" H 4050 2950 50  0001 C CNN
	1    4050 2950
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5D9101E3
P 3950 2950
F 0 "R1" H 4100 2900 50  0000 C CNN
F 1 "4.7k" H 4075 2975 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3950 2950 50  0001 C CNN
F 3 "~" H 3950 2950 50  0001 C CNN
	1    3950 2950
	-1   0    0    1   
$EndComp
Wire Wire Line
	3950 2850 3950 2800
Wire Wire Line
	3950 2800 4050 2800
Wire Wire Line
	4050 2800 4050 2850
Text GLabel 3950 2800 0    50   Input ~ 0
3v3
$Comp
L MCU_Microchip_ATtiny:ATtiny45-20SU U2
U 1 1 5D9422A8
P 2825 4575
F 0 "U2" H 2295 4621 50  0000 R CNN
F 1 "ATtiny45-20SU" H 2295 4530 50  0000 R CNN
F 2 "Package_SO:SOIJ-8_5.3x5.3mm_P1.27mm" H 2825 4575 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf" H 2825 4575 50  0001 C CNN
	1    2825 4575
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5D948F11
P 2825 5175
F 0 "#PWR02" H 2825 4925 50  0001 C CNN
F 1 "GND" H 2830 5002 50  0000 C CNN
F 2 "" H 2825 5175 50  0001 C CNN
F 3 "" H 2825 5175 50  0001 C CNN
	1    2825 5175
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5D949244
P 3550 4175
F 0 "C2" H 3642 4221 50  0000 L CNN
F 1 "0.01uF" H 3642 4130 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3550 4175 50  0001 C CNN
F 3 "~" H 3550 4175 50  0001 C CNN
	1    3550 4175
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3975 3550 4075
$Comp
L power:GND #PWR01
U 1 1 5D94B1BE
P 3550 4275
F 0 "#PWR01" H 3550 4025 50  0001 C CNN
F 1 "GND" H 3555 4102 50  0000 C CNN
F 2 "" H 3550 4275 50  0001 C CNN
F 3 "" H 3550 4275 50  0001 C CNN
	1    3550 4275
	1    0    0    -1  
$EndComp
Text GLabel 1850 4575 0    50   Input ~ 0
BoronEN
$Comp
L Device:R_Small R3
U 1 1 5D959DA0
P 1650 4775
F 0 "R3" V 1550 4775 50  0000 C CNN
F 1 "10k" V 1650 4775 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1650 4775 50  0001 C CNN
F 3 "~" H 1650 4775 50  0001 C CNN
	1    1650 4775
	0    -1   -1   0   
$EndComp
Text GLabel 3950 3050 3    50   Input ~ 0
SDA
Text GLabel 4050 3050 3    50   Input ~ 0
SCL
Text GLabel 3300 2100 2    50   Input ~ 0
ATTINYRQ
Text GLabel 1850 4675 0    50   Input ~ 0
ATTINYRQ
Text Label 2050 4775 0    50   ~ 0
RST
$Comp
L MargoGeneral:BoronV1.0 U4
U 1 1 5D9840F9
P 2100 2950
F 0 "U4" H 2650 4815 50  0000 C CNN
F 1 "BoronV1.0" H 2650 4724 50  0000 C CNN
F 2 "Margo_Lib:BoronV1.0" H 1750 2650 50  0001 C CNN
F 3 "" H 1850 2750 50  0001 C CNN
	1    2100 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5D993A8B
P 2650 6450
F 0 "#PWR03" H 2650 6200 50  0001 C CNN
F 1 "GND" H 2655 6277 50  0000 C CNN
F 2 "" H 2650 6450 50  0001 C CNN
F 3 "" H 2650 6450 50  0001 C CNN
	1    2650 6450
	1    0    0    -1  
$EndComp
$Comp
L Connector:AVR-ISP-6 J2
U 1 1 5D9924B1
P 2550 6050
F 0 "J2" H 2270 6146 50  0000 R CNN
F 1 "AVR-ISP-6" H 2270 6055 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 2300 6100 50  0001 C CNN
F 3 " ~" H 1275 5500 50  0001 C CNN
	1    2550 6050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2150 6150 2050 6150
Wire Wire Line
	2050 6150 2050 4775
Wire Wire Line
	1750 4775 2050 4775
Wire Wire Line
	2150 6050 2000 6050
Wire Wire Line
	2000 6050 2000 4475
Wire Wire Line
	1950 4375 1950 5850
Wire Wire Line
	1950 5850 2150 5850
Wire Wire Line
	2150 5950 1900 5950
Wire Wire Line
	1900 5950 1900 4275
Text GLabel 1850 4275 0    50   Input ~ 0
SDA
Wire Wire Line
	1850 4275 1900 4275
Connection ~ 1900 4275
Wire Wire Line
	1850 4475 2000 4475
Connection ~ 2000 4475
Text Label 2050 4375 0    50   ~ 0
MISO
$Comp
L Device:Jumper_NC_Small JP1
U 1 1 5D910E20
P 3975 1900
F 0 "JP1" H 3975 2112 50  0000 C CNN
F 1 "Jumper_NC_Small" H 3975 2021 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 3975 1900 50  0001 C CNN
F 3 "~" H 3975 1900 50  0001 C CNN
	1    3975 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1900 3875 1900
Text GLabel 3550 3975 2    50   Input ~ 0
LiPo+
Text Notes 3525 3850 0    50   ~ 0
Probably need some sort of low power watch
Text GLabel 2650 5550 2    50   Input ~ 0
LiPo+
Text GLabel 1550 4775 0    50   Input ~ 0
LiPo+
$Comp
L Device:C_Small C1
U 1 1 5D90C45D
P 2050 6250
F 0 "C1" H 1700 6275 50  0000 L CNN
F 1 "0.01uF" H 1700 6200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2050 6250 50  0001 C CNN
F 3 "~" H 2050 6250 50  0001 C CNN
	1    2050 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5D90D261
P 2050 6350
F 0 "#PWR0101" H 2050 6100 50  0001 C CNN
F 1 "GND" H 2055 6177 50  0000 C CNN
F 2 "" H 2050 6350 50  0001 C CNN
F 3 "" H 2050 6350 50  0001 C CNN
	1    2050 6350
	1    0    0    -1  
$EndComp
Connection ~ 2050 6150
Wire Wire Line
	1900 4275 2225 4275
Wire Wire Line
	1950 4375 2225 4375
Wire Wire Line
	2000 4475 2225 4475
Wire Wire Line
	1850 4575 2225 4575
Wire Wire Line
	1850 4675 2225 4675
Wire Wire Line
	2225 4775 2050 4775
Connection ~ 2050 4775
Text Label 2050 4475 0    50   ~ 0
SCK
Wire Wire Line
	2825 3975 3550 3975
Text Label 2050 4275 0    50   ~ 0
MOSI
Text GLabel 2000 1500 0    50   Input ~ 0
3v3
$EndSCHEMATC