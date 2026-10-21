#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
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

	if (primeiro == NULL) //verifica se a lista esta vazia e avisa
	{
		primeiro = novo;
	}
	else
	{
		// procura o final da lista
		// NO* aux = primeiro;
		// while (aux->prox != NULL) {
		// 	aux = aux->prox;
		// }
		// aux->prox = novo;

		NO* atual = primeiro; NO* anterior = NULL;

		// enquanto o atual n/for nulo (pra n/dar erro) e tiver um valor menor que o "novo"
		while (atual != NULL && atual->valor < novo->valor)
		{
			//Percorre a lista com os 2 ponteiros
			anterior = atual;
			atual = atual->prox;
		}

		//Se o atual n/for nulo (pra n/dar erro)...
		// e tiver um valor igual ao "novo"
		if (atual != NULL && atual->valor == novo->valor){
			cout << "Elemento repetido. "; //avisa a repetição
			free(novo); //libera o espaço alocado p/o novo
			return;
		}

		//se o anterior ainda for nulo (n/rodou a repetição)
		if (anterior == NULL){

			primeiro = novo; // o novo elemento vira o primeiro
			novo->prox = atual; //e o atual (antigo primeiro) vira o segundo
			return;

		}
		else{ //senão

			//insere o novo entre o anterior e o atual (reajustando os ponteiros)

			anterior->prox = novo; 
			novo->prox = atual;

		}
		
		
		
	}
}

void excluirElemento()
{
	//se lista tiver vazia avisa e sai
	if (primeiro == NULL){
		cout << "Lista vazia.";
		return;
	}

	NO* atual = primeiro;
	NO* anterior = NULL;
	int numero;

	//pede e guarda o numero
	cout << "Digite o elemento que deseja excluir: ";
	cin >> numero;
	
	// enquanto o atual n/for nulo (primeiro pra n/dar erro)
	// e o valor atual for menor que o numero
	while (atual != NULL && atual->valor < numero)
	{
		//percorre a lista com 2 ponteiros
		anterior = atual; 
		atual = atual->prox;	
	}
	if (atual == NULL){ //se atual for nulo, não encontrou até o fim
		cout << " ELEMENTO NAO ENCONTRADO. ";
		return; //e sai.
	}
	if (atual->valor == numero){ //se o valor atual for o numero

		if(atual == primeiro){ //se o atual for o primeiro
		primeiro = primeiro->prox; // o primeiro vira o segundo
		free(atual); // e limpa o atual (antigo primeiro)
		return; // e sai.
	
	}
	else{//se n/for o primeiro
	
		anterior->prox = atual->prox; //o próximo do anterior vira o próximo do atual.
		free(atual); // limpa o atual
		return; // e sai
	}

	}
	else{ //se o valor atual ainda n/for o número, n/encontrou.
		cout << " ELEMENTO NAO ENCONTRADO. ";
	}


}

void buscarElemento()
{
	// verifica se a lista esta vazia e avisa
	if (primeiro == NULL){
		cout << "Lista vazia.";
		return;
	}

	NO* aux = primeiro;
	int numero;

	// pede e guarda o numero
	cout << "Digite o elemento que busca: ";
	cin >> numero;
	
	// enquanto o aux n/for nulo (primeiro pra n/dar erro)
	// e o valor do aux for menor que o numero
	while (aux != NULL && aux->valor < numero)
	{
		aux = aux->prox;	//aux percorre a lista
	}
	if (aux == NULL){ //se aux for nulo, não encontrou até o fim
		cout << " ELEMENTO NAO ENCONTRADO. ";
		return; // e sai
	}
	if (aux->valor == numero){ //se o valor de aux for o número, encontrou e sai
		cout << "ENCONTRADO ";
		return;
	}
	else{ //senão, não encontrou.
		cout << " ELEMENTO NAO ENCONTRADO. ";
	}

}


