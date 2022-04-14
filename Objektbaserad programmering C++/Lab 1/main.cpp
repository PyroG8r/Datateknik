/*
    Emil Jons
    2022-03-24
    Objektbaserad programmering
    Lab 1 - Structs
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
struct Adress {
    std::string street,city;
    int zip;
};
struct Person {
    std::string name, id;
    Adress location;

};
std::vector<Person> read_file(std::string filename);
size_t find_in_names( const std::vector <Person>&haystack, std::string name_part);
std::vector <Person> find_person_from_city(const std::vector <Person>&haystack, std::string city);
std::istream &operator>> (std::istream & in, Person &p);
void string_to_lower(std::string&s);

int main(){
    std::string filename = "names.txt";
    std::vector<Person> persons = read_file(filename);
    std::vector<Person> persons_from_city;
    int option;
    std::string temp;
    std::cout << "1. Sök del av personnamn" << std::endl << "2. Sök efter personer i stad (endast exakta matchningar)." << std::endl << "3. Avsluta" << std::endl;
    std::cin >> option;
    switch(option){
        case 1: 
            std::cin.ignore();
            std::cout << "Sök del av personnamn." << std::endl;
            std::getline(std::cin, temp);
            std::cout << find_in_names(persons, temp) << std::endl;
            break;
        case 2: 
            std::cin.ignore();
            std::cout << "Sök efter personer i stad(endast exakta matchningar)." << std::endl;
            std::getline(std::cin, temp);
            for (Person p : find_person_from_city(persons,temp)) {
                std::cout << p.id << ", " << p.name << ", " << p.location.zip << ", " << p.location.city << std::endl;
            }
            break;
        case 3: 
            std::cin.ignore();
            std::cout << "Avsluta." << std::endl;
            break;
        default:
            break;
    }

    
}


std::vector<Person> read_file(std::string filename) {
    std::ifstream file;
    file.open(filename);
    Person person_temp;
    std::vector<Person> haystack;
    if(file.is_open()){
        file >> person_temp;    //Kör en gång innan loopen för att iterera rätt antal gånger genom filen
        while(!file.eof()){
            haystack.push_back(person_temp);    //Lägger personen i vectorn
            file >> person_temp;    //Matar in en ny person
        }
    }
    else{
        std::cout << "Kunde inte öppna filen..." << std::endl;        //Felhantering
    }
    file.close();
    return haystack;
}


size_t find_in_names ( const std::vector < Person >&haystack, std::string name_part ){
    size_t nr=0;
    std::string temp_name;
    for (Person p : haystack){
        temp_name = p.name; //Sätter namnet till en temporär variabel så att inte orginal namnet ändrar formatering
        string_to_lower(temp_name);
        string_to_lower(name_part);
        size_t found=temp_name.find(name_part);
        if (found!=std::string::npos)    //Om den inte hittar namnet i strängen kommer "found" vara konstanten "npos"
            nr++;                   //Lägger till ett om "found" är annat än npos
    }
    return nr;
}

std::vector<Person>find_person_from_city(const std::vector <Person>&haystack, std::string city){
    std::vector<Person> person_from_city;    //temporär vector som innehåller alla matchningar
    std::string temp_city;   
    for (Person p : haystack){
        temp_city = p.location.city;
        string_to_lower(temp_city);
        string_to_lower(city);
        if (temp_city == city){ 
            person_from_city.push_back(p);  //pushar in alla matchade p i vectorn
        }
    }
    return person_from_city;
}

std::istream &operator>> (std::istream &in, Person &p){
    std::string street, zip, city, adress;
    size_t pos;

    getline(in, p.name);        //Läser in första
    getline(in, p.id);          //Läser in andra
    getline(in, adress, '\n');  //Läser in hela sista raden
    if(in.eof()){   // Kontrollerar om filen är slut för att inte fortstätta när inte finns några personer kvar
        return in;
    }
    pos = adress.find(",");         //hittar comma tecknet för att utgå ifrån det i extraheringen av adressen
    street = adress.substr(0, pos); //från början till comma
    zip = adress.substr(pos+2, 6);  //från comma + 2 till slut av zip koden
    zip.erase(zip.begin()+3);       // tar bort mellanrummer i zipkoden så att ingen information försvinner när den konverteras till en int
    city = adress.substr(pos+10);   //från början av stadsnamnet till slutet av raden
    
    
    for (int i = 0; i < city.length(); i++){        //for loop för att hitta var stadsnamnet slutar
        if (city[i] != ' ')
            pos = i;
    }
    city = city.substr(0,pos+1);        //ta bort alla blanksteg efter stadsnamnet

    p.location.street = street;
    p.location.city = city;
    p.location.zip = std::stoi(zip);
    
    return in;
}

void string_to_lower(std::string&s){
    size_t pos;

    pos=s.find("Ä");        //Letar efter "Ä"
    while (pos!=std::string::npos){  //Om "Ä" hittas
        s.replace(pos, 2, "ä");  //Byt ut "Ä" mot "ä"
        pos=s.find("Ä");    //Letar om det finns nåt mera "Ä"
    }

    pos=s.find("Å");    //Samma sak för Å
    while (pos!=std::string::npos){
        s.replace(pos, 2, "å");
        pos=s.find("Å");
    }

    pos=s.find("Ö");    //Samma sak för Ö
    while (pos!=std::string::npos){
        s.replace(pos, 2, "ö");
        pos=s.find("Ö");
    }

    for (auto &c : s){      // Går igenom alla karaktärer i strängen och sätter dem till lower
        c = static_cast<char>(tolower(static_cast<int>(c)));
    }
}
