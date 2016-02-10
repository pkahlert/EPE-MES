P = 0.5 ; 2408 ; 1451

P Wert ab jetzt negativ
P = 0.05; 2373 ; 1447

Faktor laser berechnung 2,89


# TI's Fehler ausbaden

Das Makefile des Demoprogramms nutzt teilweise fehlerhaft (s. http://e2e.ti.com/support/microcontrollers/c2000/f/171/p/326227/1136098 ) absolute Pfade, zum Beheben haben wir einen symbolischen Link auf das "angebliche" Verzeichnis gesetzt:

```cmd
mklink /D "C:\TI\controlSUITE2_DMC Rev" "C:\Beuth\ti_controlSUITE\"
```

# Anforderungen
* der Motor (Typ MDFMAIG071-12D, Typenschild s. Slack) ist mit einem Drehfeld zu regeln (auf Drehzahl)
* ein PWM-Signal ist zu utilisieren
* ein Modell bildet den Motor-/Generator-Pr�fstand hinreichend ab
* das Modell beinhaltet das Regelkonzept


# Plan
- erster Plan
  - Matlab importieren
  - gescheitert an elektr. Modell und dependency-Problemen
  - wie in Simulink feldorientiert regeln mit Drehzahl als input und Ausgabe der sechs PWM-Duty-Cycles die die Mosfets beschalten
  
  
- tatsächliche Realisierung
  - Inkrementieren einer Zählvariable
  - Nutzen der Zählvariable als Index für ein vorgeneriertes Array mit Sinuswerten
  - diese Sinuswerte werden jeweils um ein Drittel verschoben in Form von Duty-Cycles auf die sechs PWMs gegeben, bei denen jeweils zwei zu Schalter-Paaren zusammengefasst und sich zueinander entgegengesetzt verhalten
  - die Duty-Cycle-Werte sind Dezimal bezogen auf eine festgelegte Periode von 2000 ausgerechnet
  - Beim Übertragen der Werte wird so der Reload-Wert des jeweiligen ePWM-Registers gesetzt, der damit die Zeit für beide logischen Zustände festlegt
  - unmodifiziert wäre das der Betrieb auf fester Drehzahl mit Stellreserve (nicht übermoduliert)
  
# PWM Konfig
j4 - 11, 49
j5 - gpio10

j5 - 4 = gpio00 = 6x so schnell wie die anderen, wird in B1() gesetzt


GPIO-00 - PIN FUNCTION = PWM1A
GPIO-01 - PIN FUNCTION = PWM1B
GPIO-02 - PIN FUNCTION = PWM2A
GPIO-03 - PIN FUNCTION = PWM2B
GPIO-04 - PIN FUNCTION = PWM3A (evtl b)
GPIO-05 - PIN FUNCTION = PWM3B (evtl a)
GPIO-06 - PIN FUNCTION = PWM4A

