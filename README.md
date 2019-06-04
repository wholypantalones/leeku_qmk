#QMK for Leeku PCBS

[https://geekhack.org/index.php?topic=97623.msg2702250#msg2702250](https://geekhack.org/index.php?topic=97623.msg2702250#msg2702250)

if you place the folder you want to use into the QMK keyboards folder and then run

		make l3_tkl87:default

You can then flash the hex using the loadfw.bat file (referencing the newly created QMK hex file of course)

Note that configuring LEDs and RGB backlighting in QMK is tricky for these boards. I've only managed to get an LED indicator on layer activation to work.
