%% Start Phase
figure(1);
subplot(3,1,1);
plot(tout,w);
legend('Soll-Wert','Ist-Wert');
title('Drehzahl im Vergleich Soll - Ist');
xlabel('t in s');
ylabel('w in n/m');

subplot(3,1,2);
plot(tout,uvw);
title('Ansteuerung des Motors');
xlabel('t in s');
ylabel('U in V');
legend('U(t)','V(t)','W(t)');

subplot(3,1,3);
plot(tout,m);
title('Drehmoment Vergleich Last - Motor');
xlabel('t in s');
ylabel('M in Nm');
legend('M Motor','M Last');