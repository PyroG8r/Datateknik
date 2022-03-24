#! python3
# filnamn: emjo2109_2.1_v1.py
# Skrivet av: Emil Jons
# Skapat datum: 2021-09-26
# Senast ändrat: 2021-09-26
# Kurs: Grundläggande Datavetenskap
# Handledare: Nayeb Maleki
# Beskrivning: Läser in ett heltal, kontrollerar om talet är udda eller jämnt med hjälp av modolusoperatatorn (%)

heltal = int(input("Skriv in ett heltal: " ))

uddajämnt = heltal % 2
if (uddajämnt == 0):
    print(heltal, "är ett jämnt tal")
else :
    print(heltal, "är ett udda tal.")