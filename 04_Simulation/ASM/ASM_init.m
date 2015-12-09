
%% Allgemeine Parameter
wb  = 2*pi*50;        % Signalfrequenz
fHz = 200; 


%% Maschinen Parameter
p  = 4;
J  = 0.28;
Lr = 0.04e-3;
Ls = 0.04e-3;
Lm = 0.42e-3;
Rs = 10;
Rr = 6.3;
Xm  = wb*Lm; % 
Xls = wb*Ls; % 
Xlr = wb*Lr; % 
Xmlstern = 1/(1/Xls+1/Xm+1/Xlr);

%% Gewollte Parameter

we = 2*pi*(fHz/p);   % Statorfrequenz

%% Last Parameter

Tl = 0;
