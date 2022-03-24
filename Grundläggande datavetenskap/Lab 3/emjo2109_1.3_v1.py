#! python3
# filnamn: emjo2109_1.3_v1.py
# Skrivet av: Emil Jons
# Skapat datum: 2021-09-26
# Senast ändrat: 2021-09-26
# Kurs: Grundläggande Datavetenskap
# Handledare: Nayeb Maleki
# Beskrivning: Ett program som först läser in ett pris utan moms, beräknar momsen och priset med moms

prisUtanMoms = int(input("Priset utan moms: " ))
momsSats = 0.25
print("Momsen är", prisUtanMoms * momsSats, "kr")
print("Priset med moms är ", prisUtanMoms * (1+momsSats), "kr")
