#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



void inserir_notas(aluno *dados_alunos[3],char nome_materia[13][25]){
    int j,i;
    char matricula_aluno[50],pos;
    printf("\nDIGITE A MATRICULA :   ");
    scanf("%s",&matricula_aluno);

    for(i = 0; i<3; i++){
        if(strcmp(matricula_aluno, dados_alunos[i]->matricula[i]) == 0){
            pos=i;
        }
    }
    printf("COMPLETE COM AS NOTAS : ");
    for(j = 0; j<13; j++){
        printf("%s ", nome_materia[j]);
        scanf("%f",dados_alunos[pos]->media[j]);
    }

}
void inserir_faltas(aluno *dados_alunos[3], char nome_materia[13][25]){
    int j,i;
    char matricula_aluno[50],pos;
    printf("\nDIGITE A MATRICULA :   ");
    scanf("%s",&matricula_aluno);

    for(i = 0; i<3; i++){
        if(strcmp(matricula_aluno, dados_alunos[i]->matricula) == 0){
            pos=i;
        }
    }
    printf("COMPLETE COM AS FALTAS : ");

    for(j = 0; j<13; j++){
        printf("%s ", nome_materia[j]);
        scanf("%f",dados_alunos[pos]->faltas[j]);
    }

}

//LOGAR E CONFERIR ALUNO
int logar_aluno(aluno *dados_alunos[3]){

    int i,pos_aluno,pos;
    char login_aluno[50], senha_aluno[50];

    printf("\nDIGITE O LOGIN :   ");
    scanf("%s",&login_aluno);
    printf("\nDIGITE A SENHA :   ");
    scanf("%s",&senha_aluno);

    printf("antes do pos");
    pos = confere_aluno(&dados_alunos,login_aluno, senha_aluno);

    printf("depois do pos");

    return pos;
}

int confere_aluno(aluno *dados_alunos[3],char login_aluno[50], char senha_aluno[50]){

    int i, pos_aluno=0;
    printf("\nentrou no confere");
    for(i = 0; i<3; i++){
    printf("\nlogin da entrada %s \n\n login do struct%s ",login_aluno, dados_alunos[i]->login_aluno);
        if(strcmp(login_aluno, dados_alunos[i]->login_aluno) == 0){
            pos_aluno=i;
            printf("%entrou no if");
        }
    }

    if(strcmp(senha_aluno, dados_alunos[pos_aluno]->senha_aluno) == 0){
        return pos_aluno;
    }else{
        logar_aluno(&dados_alunos);
    }
}

//LOGAR E CONFERIR SECRETÁRIO
void logar_secretario(aluno dados_secretario[3]){

    int i,pos_aluno;
    char login_aluno[50], senha_aluno[50];

    printf("\nDIGITE O LOGIN :   ");
    scanf("%s",&login_aluno);
    printf("\nDIGITE A SENHA :   ");
    scanf("%s",&senha_aluno);

    confere_secretario(&dados_secretario,login_aluno, senha_aluno);
}

void confere_secretario(secretario *dados_secretario[3], char login_secretario[50], char senha_secretario[50]){

    int i, pos_sec;

    for(i = 0; i<3; i++){
        if(strcmp(login_secretario, dados_secretario[i]->login_func) == 0){
            pos_sec=i;
        }
    }

    if(strcmp(login_secretario, dados_secretario[pos_sec]->senha_func) == 0){
        printf("LOGIN FEITO COM SUCESSO !");
    }else{
        logar_secretario(&dados_secretario);
    }
}

void exibe_dados_alunos(aluno *dados_alunos[], char nome_materia[13][25]){

    int i,j,k;

    for( i = 0; i< 10; i++ ){
        printf("NOME                : %s",  dados_alunos[i]->nome);
        printf("MATRICULA           : %i",  dados_alunos[i]->matricula);
        printf("LOGIN               : %s",  dados_alunos[i]->login_aluno);
        printf("SENHA               : %s",  dados_alunos[i]->senha_aluno);
        printf("MEDIAS              : %s",  dados_alunos[i]->senha_aluno);

        for(j = 0; j<13; j++){
            printf("%s %f", nome_materia[j],dados_alunos[i]->media[j]);
        }

        printf("FALTAS              : %s",  dados_alunos[i]->senha_aluno);

        for(j = 0; j<13; j++){
            printf("%s %i", nome_materia[j],dados_alunos[i]->faltas[j]);
        }
    }
}
void exibe_dados_alunos_aluno(int pos,aluno *dados_alunos[], char nome_materia[13][25]){
    int i=pos,j,k;
    printf("NOME                : %s",  dados_alunos[i]->nome);
    printf("MATRICULA           : %i",  dados_alunos[i]->matricula);
    printf("LOGIN               : %s",  dados_alunos[i]->login_aluno);
    printf("SENHA               : %s",  dados_alunos[i]->senha_aluno);
    printf("MEDIAS              : ");
    for(j = 0; j<13; j++){

        printf("%s %f", nome_materia[j],dados_alunos[i]->media[j]);

        if(dados_alunos[i]->media[j]<7){
            printf("Está de recuperação em : %s",nome_materia[j]);
        }
    }
    printf("FALTAS              : %s",  dados_alunos[i]->senha_aluno);

    for(j = 0; j<13; j++){
        printf("%s %i", nome_materia[j],dados_alunos[i]->faltas[j]);
    }

}
void menu(aluno *dados_alunos[3], secretario *dados_funcionarios[2], char nome_materia[13][25]){

    int entrada_menu, pos,entrada_aluno,entrada_sec;

    printf("\n\nESCOLHA UMA OPÇÃO :");
    printf("\n1 - LOGAR COMO ALUNO");
    printf("\n2 - LOGAR COMO SECRETÁRIO");
    printf("\nRESPOSTA :   ");
    scanf("%i", &entrada_menu);

    switch (entrada_menu){
        case 1:
            system("cls");

            pos = logar_aluno(&dados_alunos);
            printf("\n1 - DESEJA VISUALIZAR SEUS DADOS? ( 1 = NAO, 1 = SIM");
            scanf("%i",&entrada_aluno);
            if( entrada_aluno==1){
                exibe_dados_alunos_aluno(pos, &dados_alunos, nome_materia);
            }else{
                printf("NÃO SEI O QUE EXIBIR AQUI");
            }

            break;
        case 2:
            system("cls");
            logar_secretario(&dados_funcionarios);
            printf("\n\nESCOLHA UMA OPÇÃO :");
            printf("\n1 - INSERIR NOTAS");
            printf("\n2 - INSERIR FALTAS");
            printf("\nRESPOSTA :   ");
            scanf("%i",&entrada_sec);
            if( entrada_sec==1){
                inserir_notas(&dados_alunos,nome_materia);
            }
            if( entrada_sec==2){
                inserir_faltas(&dados_alunos,nome_materia);
            }
            break;
    }
}
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
    arq1 = fopen("sec.txt", "r");             // LEITURA DO TXT DE SECRETÁRIOS
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

    menu(&dados_alunos,&dados_funcionarios, nome_materia);














 return 0;
}
