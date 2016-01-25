
%Parameter der Maschine im Labor
Rr=32.6;			
Rs=26.3;			
Lls=6.7e-2;		
Llr=6.7e-2;		
Lm=0.96;		
fb=50;		
P=4;		


%Rr=.5;			
%Rs=.5;			
%Lls=.5e-3;		
%Llr=.5e-3;		
%Lm=5e-3;		
%fb=100;			
%p=4;			

%Reglerparameter
P1=2;                                                            
I1=0.02;                                                                
P2=10;                                                               
I2=0.01;                                                              
P3=10;                                                              
I3=0.01;                                                                  
Lr=Llr+Lm;
Tr=Lr/Rr;

%Berechnungen
wb=2*pi*fb;                         %Netzfrequenz
Xls=wb*Lls;                         %Blindwiderstand tänder
Xlr=wb*Llr;                         %Blindwiderstand Rotor
Xm=wb*Lm;                           %Blindwiderstand Hauptinduktivität
Xmstar=1/(1/Xls+1/Xm+1/Xlr);        %Blindwiderstand Gesamtinduktivität

Ud=400;                             %Gleichspannungsversorgung
ids=0.718;                          %Magnetisierungsstrom

%Ausgabe 

sim('IFOR',1);

figure;
plot(simout7.signals.values, 'DisplayName', 'simout7.signals.values', 'YDataSource', 'simout7.signals.values'); grid; title('Phasenströme I_U; I_V, I_W');xlabel('Sample Time');ylabel('I/p.u.');
figure;
plot(simout8.signals.values, 'DisplayName', 'simout8.signals.values', 'YDataSource', 'simout8.signals.values'); grid; title('SOLL und IST Drehzahl');xlabel('Sample Time');ylabel('w_r');
figure
plot(simout9.signals.values, 'DisplayName', 'simout9.signals.values', 'YDataSource', 'simout9.signals.values');grid; title('SOLL und IST Drehmoment');xlabel('Sample Time');ylabel('M/p.u.');

