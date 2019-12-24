#include <stdio.h>
#include <stdlib.h>

//structs
typedef struct {
    char nome[50];
    char matricula[10];
    float media[13];
    float media_final;
    int faltas[13];
    float falta;
    char login_aluno[50];
    char senha_aluno[50];
  } aluno;

typedef struct {
    char codigo[50];
    char login_func[50];
    char senha_func[50];
    } secretario;

/*void exibe_dados_alunos(aluno dados_alunos[], char nome_materia[13][25]){
    int i,j,k;
    for( i = 0; i< 10; i++ ){
            printf("NOME                : %s",  dados_alunos[i].nome);
            printf("MATRICULA           : %i",  dados_alunos[i].matricula);
            printf("LOGIN               : %s",  dados_alunos[i].login_aluno);
            printf("SENHA               : %s",  dados_alunos[i].senha_aluno);
            printf("MEDIAS              : %s",  dados_alunos[i].senha_aluno);
            for(j = 0; j<13; j++){
                printf("%s %f", aluno.media[j]);
            }
            printf("FALTAS              : %s",  dados_alunos[i].senha_aluno);
            for(j = 0; j<13; j++){
                printf("%s %i", aluno.faltas[j]);
            }
            for(j = 0; j<13; j++){
                dados_alunos[i].media+=dados_alunos.media[i];
            }
    }
}*/

/*void ler_txt_aluno(aluno *dados_alunos[3], char *result, FILE *arq){
    while (!feof(arq)){
            int i;
    char Linha[100];
            //ler aluno
            // LÊ UMA LINHA (INCLUSIVE COM O '\N')
           // O 'FGETS' LÊ ATÉ 99 CARACTÉRES OU ATÉ O '\N'
            if (result){  // SE FOI POSSÍVEL LER VAI EXECUTAR
                for(i = 0; i<3; i++){
                    result = fgets(Linha, 100, arq);//NOME
                    //dados_alunos[i]->nome=result;
                    sprintf(dados_alunos[i]->nome, "%s", result);
                    printf("NOME                : %s",  dados_alunos[i]->nome);
                    result = fgets(Linha, 100, arq);//MATRICULA
                    dados_alunos[i]->matricula=atoi(result);
                    result = fgets(Linha, 100, arq);//LOGIN
                    sprintf(dados_alunos[i]->login_aluno, "%s", result);
                    result = fgets(Linha, 100, arq);//SENHA
                    sprintf(dados_alunos[i]->senha_aluno, "%s", result);
                }
            }


}
}*/
int main()
{
    //VARIÁVEIS
    int i;
    FILE *arq, *arq1;
	char Linha[100];
	char *result;
	arq = fopen("est.txt", "r");             // LEITURA

    aluno dados_alunos[3];
    secretario dados_funcionarios[2];

    char nome_materia[13][25]={"LINGUA PORTUGUESA   : ",  //vetor de strings para armazenar os nomes das matérias
                               "MATEMATICA          : ",
                               "BIOLOGIA            : ",
                               "FISICA              : ",
                               "QUIMICA             : ",
                               "FILOSOFIA           : ",
                               "INGLES              : ",
                               "GEOGRAFIA           : ",
                               "HISTORIA            : ",
                               "SOCIOLOGIA          : ",
                               "EDUCACAO FISICA     :",
                               "EDUCAO ARTISTICA    :",
                               "LITERATURA          :"
                          };

    while (!feof(arq)){//ALUNO
            // LÊ UMA LINHA (INCLUSIVE COM O '\N')O 'FGETS'
            if (result){  // SE FOI POSSÍVEL LER VAI EXECUTAR
                for(i = 0; i<3; i++){
                    result = fgets(Linha, 100, arq);//NOME
                    sprintf(dados_alunos[i].nome, "%s", result);
                    printf("\nNOME                : %s",  dados_alunos[i].nome);

                    result = fgets(Linha, 100, arq);//MATRICULA
                    sprintf(dados_alunos[i].matricula, "%s", result);
                    printf("MATRICULA           : %s",  dados_alunos[i].matricula);

                    result = fgets(Linha, 100, arq);//LOGIN
                    sprintf(dados_alunos[i].login_aluno, "%s", result);
                    printf("LOGIN               : %s",  dados_alunos[i].login_aluno);

                    result = fgets(Linha, 100, arq);//SENHA
                    sprintf(dados_alunos[i].senha_aluno, "%s", result);
                    printf("SENHA               : %s",  dados_alunos[i].senha_aluno);
                }
            }
}
fclose(arq);
printf("\n\n-------------------------------------------------");
arq1 = fopen("sec.txt", "r");             // LEITURA
    while (!feof(arq1)){//SECRETARIO
        // LÊ UMA LINHA (INCLUSIVE COM O '\N')O 'FGETS'
        if (result){  // SE FOI POSSÍVEL LER VAI EXECUTAR
            for(i = 0; i<2; i++){

                result = fgets(Linha, 100, arq);//CODIGO
                sprintf(dados_funcionarios[i].codigo, "%s", result);
                printf("\n\nCODIGO               : %s",  dados_funcionarios[i].codigo);

                result = fgets(Linha, 100, arq);//LOGIN
                sprintf(dados_funcionarios[i].login_func, "%s", result);
                printf("LOGIN               : %s",  dados_funcionarios[i].login_func);

                result = fgets(Linha, 100, arq);//SENHA
                sprintf(dados_funcionarios[i].senha_func, "%s", result);
                printf("SENHA               : %s",  dados_funcionarios[i].senha_func);
            }
        }
    }
















 return 0;
}
