#include <tp5.h>
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});


int HashTable::hash(std::string element)
{
    // use this->size() to get HashTable size

    int ascii = (int) (element[0]); 
    if(ascii > this->size()-1)
    {
        ascii = ascii%this->size(); 
    }
    return ascii; 
}

void HashTable::insert(std::string element)
{
    // use (*this)[i] or this->get(i) to get a value at index i
     
    this->get(hash(element)) = element; 
}

/**
 * @brief buildHashTable: fill the HashTable with given names
 * @param table table to fiil
 * @param names array of names to insert
 * @param namesCount size of names array
 */

void buildHashTable(HashTable& table, std::string* names, int namesCount)
{
    table.insert(names[namesCount-1]); 
    if(namesCount>1)
    {
        buildHashTable(table, names, namesCount-1); 
    }

}

bool HashTable::contains(std::string element)
{
    // Note: Do not use iteration (for, while, ...)
    
    int ascii = hash(element); 
    if(this->get(ascii)==element)
    {
        return true; 
    }
    else
    {
        return false; 
    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 10;
	w = new HashWindow();
	w->show();

	return a.exec();
}
