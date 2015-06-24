# Arduino project using xbee, breath sensor
### part of implementation for ZZWY Studio's art project
---
 
### Operational Notes
1. In order to trigger Serail port ready. Sometimes you might need to plug micro usb cable if Xbee data is not transmitted. You can also open Arduino editor's Serial Monitor to check if data start to transmit.

 因為Arduino micro (Leonardo) 板子的緣故，我們需要等待serial port ready了才能進行接下來動作，但有時你必須插一下usb線或是開啟你的Arduino Serical Monitor來強制Serial port 開始運作。


### Some Interesting Lessons

Data transmitted via Arduino **Serial.println** might not be correct when using Processing to receive data. Instead of using println, we may use **Serial.write** to ensure data correctness.

```
	// print out the result
  	Serial.print("analog input: ");
   
   // use .write to ensure correcness
   xbeeSerial.write(output); 

``` 

There's alway a need to smooth analog sensor data. However, the resistence values from conductive rubber are varied from using 1400ma Lithium battery and micro usb as a power source. Thus, we smooth the input data mainly for using battery.

```
  // when using batter, resistence values differ from 190 - 420
  // when using usb power source, value from 135 - 290
  int output = map(sensor, 190, 420, 10, 100);
  
```


