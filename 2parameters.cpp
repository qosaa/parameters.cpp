#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <ficheiro_origem> <ficheiro_destino>" << endl;
        return 1;
    }

    ifstream ficheiroOrigem(argv[1], ios::binary);
    if (!ficheiroOrigem) {
        cerr << "Erro ao abrir o ficheiro de origem." << endl;
        return 1;
    }

    ofstream ficheiroDestino(argv[2], ios::binary);
    if (!ficheiroDestino) {
        cerr << "Erro ao criar o ficheiro de destino." << endl;
        return 1;
    }

    ficheiroDestino << ficheiroOrigem.rdbuf();

    ficheiroOrigem.close();
    ficheiroDestino.close();

    cout << "Backup concluído com sucesso!" << endl;
    return 0;
}
