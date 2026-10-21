#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL; //cria o ponteiro p/o �ltimo

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
//NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL; //deixa o ultimo nulo p/inicializar a lista
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo; //o ultimo tambem aponta para o novo
	}
	else
	{
		// procura o final da lista
		/*NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;*/

		ultimo->prox = novo; //faz o ultimo apontar para o novo 
		ultimo = novo; //o ultimo agora e o novo
	}
}

void excluirElemento()
{
	//Confere se a lista está vazia e avisa.
	if (primeiro == NULL){
			cout << "Lista vazia. ";
			return;
	}

	

	NO* atual = primeiro->prox;
	NO* anterior = primeiro;
	NO* excluir;
	int elemento;

	//se não estiver, pede o elemento

	cout << "Digite o elemento que deseja excluir: ";
	cin >> elemento;

	//Se for o primeiro...
	if (primeiro->valor == elemento) {

		excluir = primeiro; //guarda a posição original
		primeiro = primeiro->prox; //o "primeiro" vira o segundo
		if (primeiro == NULL){ ultimo = NULL;} //se a lista tiver só esse elemento, anula o "último"
		free(excluir); //exclui a posição original do primeiro
		return;

	}
	
	//se não for o primeiro, enquanto o atual não for nulo, nem a posição do elemento
		while (atual != NULL && atual->valor != elemento) {

			//percorre a lista com 2 ponteiros

			anterior = atual;
			atual = atual->prox;

		}
		
		if (atual == NULL){ //se o atual for nulo, o elemento não está na lista
			
			cout << "Elemento nao encontrado";
		}
		else{

			//se não...

			anterior->prox = atual->prox; //atualiza os ponteiros

		if (atual == ultimo) { //se o elemento for o último

			ultimo = anterior; //o último vira o penúltimo

		}
		free(atual); //exclui o elemento

		}
	
}

void buscarElemento()
{
	
}


