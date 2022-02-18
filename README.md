# 2122-mbp-07-SetDinamicArray-11v

Заданието ви е да напишете програмни реализиращи основните операции с множества на следните контейнери:

Sequence Containers- vector, list and deque Associative Containers - map и set

Всяка от реализациите трябва да е в отделен файл, необходимо е да използвате шаблонен тип за съдържащите се в контейнерите данни. Имената на файловете трябва да са имената на контейнера, с който е написано решението.

Предоставяме Ви описание на клас Set, където декларациите включват динамичен масив:

class Set { int size = 0;

int DEFAULTSIZE = 10;

int* elements = new int[size]; public: // Default constructor

Set() {};

Set(int s);

Set(vector items);

// Destructor

~Set();

int getSize() { return this->size; }

bool contains(int n);

Set unionWith(Set& Y);

Set intersectWith(Set& Y);

Set complementWith(Set& Y);

static Set symmetricComplement(Set& X, Set& Y);

static vector cartesianProduct(Set& X, Set& Y);

static void displayCartesianProduct(vector& X);

void sort();

int calcDegree();

void enterFromKeyboard();

void display(); };

