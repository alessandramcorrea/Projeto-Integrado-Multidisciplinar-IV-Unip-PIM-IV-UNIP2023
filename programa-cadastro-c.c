#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 200

int main(void)
{
   char login[20] = "alessandracorrea";
   char login1[20];
   char senha[20] = "54321";
   char senha1[20];
   char res[20] = "sim";
   char logado;
   int calcularidade;
   int retorno;
   int risco = 0;

   struct cadastro {
   char nome[SIZE];
   char email[SIZE];
   int numero;
   int dia;
   int mes;
   int ano;
   char cpf[SIZE];
   char telefone[SIZE];
   char cep[SIZE];
   char diagnostico[SIZE];
   char rua[SIZE];
   char bairro[SIZE];
   char cidade[SIZE];
   char estado[SIZE];
   char comorbidade[15];
   char quais[SIZE];
   };
   struct cadastro paciente;

   int anoatual;
   time_t data_ano;
   time(&data_ano);
   void cadastro(){};

   struct tm * data = localtime(&data_ano);
   anoatual = (data -> tm_year+1900);

   system("cls || clear");
   // system("color F4");
   printf("\nSistema de Cadastro de Pacientes com COVID-19\n");
   printf("...................................................\n\n");
   printf("Login: ");
   gets(login1);
   if (strcmp(login, login1) == 0){
    printf("Senha: ");
    gets(senha1);
    if (strcmp(senha, senha1) == 0){
        printf("\n\nLogado\n\n");
        cadastro(cadastro);
        logado = 'S';

    }
    else {
        printf("Senha invalida!Tente novamente.");
    }
   }
else {
    printf("Login invalido! Tente novamente.");
}
if (logado =='S') {
    fflush(stdin);
    FILE *ponteiroArquivo;
    ponteiroArquivo=(fopen("cadastros.txt", "a"));
    printf("\nNome do paciente: ");
    fgets(paciente.nome, 200, stdin);
    printf("CPF: ");
    fgets(paciente.cpf, 200, stdin);
    printf("Data de nascimento: ");
    printf("\nDia: ");
    fflush(stdin);
    scanf("%d", &paciente.dia);
    printf("Mes: ");
    fflush(stdin);
    scanf("%d", &paciente.mes);
    printf("Ano: ");
    fflush(stdin);
    scanf("%d", &paciente.ano);
    printf("Telefone: ");
    scanf(" %30[^\n]s", &paciente.telefone);

    printf("CEP: ");
    scanf(" %30[^\n]s", &paciente.cep);

    printf("Rua: ");
    scanf(" %30[^\n]s", &paciente.rua);

    printf("Numero: ");
    fflush(stdin);
    scanf("%d", &paciente.numero);
    printf("Bairro: ");
    scanf(" %30[^\n]s", &paciente.bairro);

    printf("Cidade: ");
    scanf(" %30[^\n]s", &paciente.cidade);

    printf("Estado: ");
    scanf(" %30[^\n]s", &paciente.estado);

    printf("Email: ");
    scanf(" %30[^\n]s", &paciente.email);

    printf("Data do diagnostico: ");
    scanf(" %30[^\n]s", &paciente.diagnostico);
    setbuf(stdin, NULL);

    printf("O paciente tem alguma comorbidade? 1 = Sim / 0 = Nao ");
    scanf("%d", &risco);
    setbuf(stdin, NULL);

    if(risco == 1)
    {
        strcpy(paciente.comorbidade, "SIM");
        printf("Se sim, escreva quais: ");

        fflush(stdin);
        fgets(paciente.quais, 200, stdin);
        }
        else{
            strcpy(paciente.comorbidade, "NÃO");
            strcpy(paciente.quais, "Nenhuma");
        }
 printf("\n");
        fprintf(ponteiroArquivo, "\nNome: %s", paciente.nome);
        fprintf(ponteiroArquivo, "CPF: %s", paciente.cpf);
        fprintf(ponteiroArquivo, "Data de nascimento: %d/%d/%d\n", paciente.dia, paciente.mes, paciente.ano);
        fprintf(ponteiroArquivo, "Telefone: %s", paciente.telefone);
        fprintf(ponteiroArquivo, "\nCEP: %s", paciente.cep);
        fprintf(ponteiroArquivo, "\nRua: %s", paciente.rua);
        fprintf(ponteiroArquivo, "\nNumero: %i\n", paciente.numero);
        fprintf(ponteiroArquivo, "Bairro: %s", paciente.bairro);
        fprintf(ponteiroArquivo, "\nCidade: %s", paciente.cidade);
        fprintf(ponteiroArquivo, "\nEstado: %s", paciente.estado);
        fprintf(ponteiroArquivo, "\nEmail: %s", paciente.email);
        fprintf(ponteiroArquivo, "\nData do diagnostico: %s", paciente.diagnostico);
        fprintf(ponteiroArquivo, "\nComorbidade: %s", paciente.comorbidade);
        fprintf(ponteiroArquivo, "\nQuais comorbidade(s)? %s\n", paciente.quais);
        calcularidade = anoatual - paciente.ano;
        if (calcularidade > 65 || risco == 1) {
            FILE *ponteiroRisco;
            ponteiroRisco=(fopen("grupoderisco.txt", "a"));
            fprintf(ponteiroRisco, "\nCEP: %s", paciente.cep);
            fprintf(ponteiroRisco, "\nIdade: %d\n", calcularidade);
            printf("\n\nO Paciente foi identificado como pertencente ao grupo de risco.\n");
            fclose(ponteiroRisco);
        }
        fclose(ponteiroArquivo);
}
}