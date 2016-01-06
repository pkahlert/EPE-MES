
%% Allgemeine Parameter
wb  = 2*pi*50;        % Signalfrequenz
fHz = 50; 
Vdc = 220; %/sqrt(3)

%% Maschinen Parameter
p  = 2;
J  = 0.0006;
Lr = 0.04e-3;
Ls = 0.04e-3;
Lm = 0.42e-3;
Rs = 30;
Rr = 30;
Xm  = wb*Lm; % 
Xls = wb*Ls; % 
Xlr = wb*Lr; % 
Xmlstern = 1/((1/Xls)+(1/Xm)+(1/Xlr));

%% Gewollte Parameter

we = 4*pi*fHz/p;   % Statorfrequenz

%% Last Parameter

Tl = 5;
