#! python3
# filnamn: emjo2109_3.2_v1.py
# Skrivet av: Emil Jons
# Skapat datum: 2021-09-26
# Senast ändrat: 2021-09-26
# Kurs: Grundläggande Datavetenskap
# Handledare: Nayeb Maleki
# Beskrivning: Ett program som hittar den största gemensamm divisorn av två inmatade heltal.


första = int(input("Skriv in ett tal: " ))
andra = int(input("Skriv in ett till tal: " ))
if(första < andra):
    M = andra
    N = första
else:
    N = andra
    M = första
R = M % N
while (R != 0 ):
    M = N
    N = R
    R = M % N
print (N)