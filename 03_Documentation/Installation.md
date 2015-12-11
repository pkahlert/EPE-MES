# TI's Fehler ausbaden

Das Makefile des Demoprogramms nutzt teilweise fehlerhaft (s. http://e2e.ti.com/support/microcontrollers/c2000/f/171/p/326227/1136098 ) absolute Pfade, zum Beheben haben wir einen symbolischen Link auf das "angebliche" Verzeichnis gesetzt:

```cmd
mklink /D "C:\TI\controlSUITE2_DMC Rev" "C:\Beuth\ti_controlSUITE\"
```