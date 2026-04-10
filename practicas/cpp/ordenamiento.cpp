#include <iostream>
#include <vector>
#include <string>

using namespace std;


void bubbleSort(vector<int>& lista, int n) {
    for (int i = 0; i <= n - 2; i++) {
        bool intercambiado = false;
        for (int j = 0; j <= n - 2 - i; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                intercambiado = true;
            }
        }
        if (!intercambiado) break;
    }
}

void selectionSort(vector<int>& lista, int n) {
    for (int i = 0; i <= n - 2; i++) {
        int min_idx = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (lista[j] < lista[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int temp = lista[i];
            lista[i] = lista[min_idx];
            lista[min_idx] = temp;
        }
    }
}

vector<int> mezclar(const vector<int>& izq, const vector<int>& der) {
    vector<int> resultado;
    int i = 0, j = 0;
    while (i < izq.size() && j < der.size()) {
        if (izq[i] <= der[j]) { resultado.push_back(izq[i]); i++; }
        else { resultado.push_back(der[j]); j++; }
    }
    while (i < izq.size()) { resultado.push_back(izq[i]); i++; }
    while (j < der.size()) { resultado.push_back(der[j]); j++; }
    return resultado;
}

vector<int> mergeSort(vector<int> lista) {
    if (lista.size() <= 1) return lista;
    int medio = lista.size() / 2;
    vector<int> izq, der;
    for (int i = 0; i < medio; i++) izq.push_back(lista[i]);
    for (int i = medio; i < lista.size(); i++) der.push_back(lista[i]);
    return mezclar(mergeSort(izq), mergeSort(der));
}



int main() {
    string algoritmo;
    int N;


    cout << "====================================================" << endl;
cout << " ____                                                  _              " << endl;
    cout << "|  _ \\ _ __ ___   __ _ _ __ __ _ _ __ ___   __ _    __| | ___         " << endl;
    cout << "| |_) | '__/ _ \\ / _` | '__/ _` | '_ ` _ \\ / _` |  / _` |/ _ \\        " << endl;
    cout << "|  __/| | | (_) | (_| | | | (_| | | | | | | (_| | | (_| |  __/        " << endl;
    cout << "|_|_  |_|  \\___/ \\__, |_|  \\__,_|_| |_| |_|\\__,_|  \\__,_|\\___|        " << endl;
    cout << " / _ \\ _ __ __| ||___/_ __   __ _ _ __ ___ (_) ___ _ __ | |_ ___  ___ " << endl;
    cout << "| | | | '__/ _` |/ _ \\ '_ \\ / _` | '_ ` _ \\| |/ _ \\ '_ \\| __/ _ \\/ __|" << endl;
    cout << "| |_| | | | (_| |  __/ | | | (_| | | | | | | |  __/ | | | || (_) \\__ \\" << endl;
    cout << " \\___/|_|  \\__,_|\\___|_| |_|\\__,_|_| |_| |_|_|\\___|_| |_|\\__\\___/|___/" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "====================================================" << endl;
    cout << "Opciones disponibles:" << endl;
    cout << " 1. burbuja" << endl;
    cout << " 2. seleccion" << endl;
    cout << " 3. mergesort" << endl;
    cout << "\nEJEMPLO DE USO:" << endl;
    cout << " Escribe: burbuja 4 50 10 30 20" << endl;
    cout << " (Esto ordenara 4 numeros usando Burbuja)" << endl;
    cout << "----------------------------------------------------" << endl;


    cout << "\n1. Elige entre los 3 ordenamientos: ";
    cin >> algoritmo;


    cout << "2. Escribe el numero de datos (N): ";
    cin >> N;


    cout << "3. Escribe los " << N << " datos desordenados: ";
    vector<int> lista(N);
    for (int i = 0; i < N; i++) {
        cin >> lista[i];
    }


    if (algoritmo == "burbuja") {
        bubbleSort(lista, N);
    } 
    else if (algoritmo == "seleccion") {
        selectionSort(lista, N);
    } 
    else if (algoritmo == "mergesort") {
        lista = mergeSort(lista);
    } 
    else {
        cout << "\nError: Algoritmo no valido." << endl;
        return 0;
    }


    cout << "\nLISTA ORDENADA:" << endl;
    for (int i = 0; i < N; i++) {
        cout << lista[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n\n----------------------------------------------------" << endl;
    

    system("pause");

    return 0;
}
