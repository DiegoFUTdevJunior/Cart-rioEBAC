#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	char arquivo[40]; //criando as STRINGs
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char idade[40];
	char cargo[40]; //final da cria��o de STRINGs
	
	printf("Digite o CPF a ser Cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s armazenando a escolha do usu�rio em uma STRING
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores de uma string para a outra
	
	FILE *file; //cria a pasta no banco de dados 
	file = fopen(arquivo, "w"); //passa o arquivo para pasta onde o sistema est� localizado//usar o "W" para criar um novo arquivo
	fprintf(file, ".\nCPF:");
	fprintf(file, cpf); //salvar o valor da vari�vel dentro do arquivo
	fclose(file); //fechando o arquivo
	
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\nNome:");//atualizar o comando escrito dentro da STRING
	fclose(file); //fechando o arquivo
	
	printf("\nDigite o Nome a ser Cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, nome);//salvar o valor da vari�vel dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\nSobrenome:");//atualizar o comando escrito dentro da STRING
	fclose(file);//fechando o arquivo
	
	printf("\nDigite o Sobrenome a ser Cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, sobrenome);//salvar o valor da vari�vel dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\nIdade:");//atualizar o comando escrito dentro da STRING
	fclose(file);//fechando o arquivo
	
	printf("\nDigite a Idade a ser Cadastrada:");
	scanf("%s", idade);
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, idade);//salvar o valor da vari�vel dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\nCargo:");//atualizar o comando escrito dentro da STRING
	fclose(file);//fechando o arquivo
	
	printf("\nDigite o Cargo a ser Cadastrado:");
	scanf("%s", cargo);
	printf("\n");
	
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, cargo);//salvar o valor da vari�vel dentro do arquivo
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");//usar o "A" para atualizar um arquivo ja existente
	fprintf(file, ".\n");//atualizar o comando escrito dentro da STRING
	fclose(file);//fechando o arquivo
	
	system("pause");	
}

int consulta() //fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem de texto, sempre que for usar acento no printf, usar o setlocale
	
	char cpf[40];//criando as STRINGs
	char conteudo[200];
	
	
	printf("Digite o CPF a ser Consultado:");
	scanf("%s", cpf);//armazenando a escolha do usu�rio
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r"); //usamos o "R" quando o programa tem que ler(consultar) o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, CPF n�o cadastrado!\n\n");
	}
		
		printf("Essas s�o as informa��es do usu�rio:");
	
	while(fgets(conteudo, 200, file) != NULL) //esta salvando todas os arquivos da FILE, para a STRING conte�do
	{
		printf("%s", conteudo);
		printf("\n");
	}
		system("pause");
		fclose(file);
		
		
}

int deletar() //fun��o respons�vel por deletar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem de texto, sempre que for usar acento no printf, usar o setlocale
	
	char cpf[40]; //usar o char mesmo quando for numeros e melhor pois com gerenciamento de STRINGS ele funciona melhor
	
	printf("Digite o CPF a ser Deletado:");
	scanf("%s", cpf);//armazenando a escolha do usu�rio
	system("cls");//limpeza do programa ap�s resposta do usu�rio
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	
	if(file == NULL)
	{
		printf("CPF N�o Encontrado no Sistema.\n\n");
		system("pause");
	}
	else
 	{
 		fclose(file);
 		remove(cpf);
 		printf("CPF Deletado com Sucesso.\n\n");
		system("pause");
	 }
	
}

int main() //a fun��o main � a respons�vel por armazenar o menu, pois � desse ponto que o usu�rio ativa as outras fun��es ou partes do programa
{
    int opcao=0; //definindo vari�veis	
	int laco=1;
	
	for(laco=1;laco=1;)//criando um la�o de repeti��o
	{
		system("cls"); //limpeza do programa ap�s resposta do usu�rio
	    setlocale(LC_ALL, "Portuguese"); //definindo linguagem de texto
	    
	
		printf("\t### Cart�rio da EBAC ###\n\n"); //inicio do menu //o comando /n serve para pular linha, e o /t pra dar espa�o no come�o
		printf("Escolha a op��o deseja no menu: \n\n");
		printf("\t1-Registrar nomes \n\n");
		printf("\t2-Consultar nomes \n\n");
		printf("\t3-Deletar nomes \n\n");
		printf("Op��o:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //limpeza do programa ap�s resposta do usu�rio
		
		switch(opcao)//inicio da sele��o do menu
		{
			case 1: //chamada de fun��es
		 	registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3: //fim da sele��o
			deletar();
			break;
			
			default: 
			printf("Essa op��o n�o est� disponivel!\n"); 
			system("pause");//esperando a resposta do usu�rio
			break;
			
			
		}
	
	}
}			


