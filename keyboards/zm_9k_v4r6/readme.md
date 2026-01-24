# Compile Firmware

qmk compile -kb zm_9k_v4r6 -km vial


# Install QMK Toolchain on Mac
https://docs.qmk.fm/newbs_getting_started  
*Select macOS Tabs*

### Install through Homebrew
```
brew install qmk/qmk/qmk
```

### Download Required Dependencies Like avr-gcc to Your System ⚠️
 ```
 qmk setup
 ```
 *Just let it clone the base qmk repo to whatever default path, you won't use it anyways*

# Pinouts for ZM 9K V4R6
| GPIO   | Net Name        |
| ------ | --------------- |
| GPIO0  | SK_DATA         |
| GPIO1  | SW1             |
| GPIO2  | SW2             |
| GPIO3  | SW3             |
| GPIO4  | SW6             |
| GPIO5  | SW5             |
| GPIO6  | SW4             |
| GPIO7  | SW9             |
| GPIO8  | SW8             |
| GPIO9  | SW7             |
| GPIO19 | ENCODER_B       |
| GPIO20 | ENCODER_A       |
| GPIO21 | ENCODER_CLICK_1 |