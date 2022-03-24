#! python3
# filnamn: emjo2109_1.2_v1.py
# Skrivet av: Emil Jons
# Skapat datum: 2021-09-26
# Senast ändrat: 2021-09-26
# Kurs: Grundläggande Datavetenskap
# Handledare: Nayeb Maleki
# Beskrivning: Programmet konverterar olika datatyper för att kunna addera dem,
# innan dem till slut skrivs ut

a = 1
b = "Ett"
c = 5.2
d = "5.2"
e = "3"

aa = "Antal " + str(a)
bb = "Antal " + b
cc = "Antal " + str(c)
dd = "Antal " + d
ee = "Antal " + e
print( aa )
print( bb )
print( cc )
print( dd )
print( ee )

aa = 10 + a
bb = '10' + b
cc = 10 + c
dd = 10 + d
ee = 10 + int(e)
print( aa )
print( bb )
print( cc )
print( dd )
print( ee )