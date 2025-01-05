#include <stdio.h>
#include <string.h>
#include <locale.h>

/**
 * struct product - A structure to represent a product.
 * @code: The unique identifier for the product.
 * @name: The name of the product.
 * @price: The price of the product.
 * @amount: The quantity of the product available.
 */
struct product
{
    int code;
    char name[50];
    float price;
    int amount;
};

void ClearScreen();
void clearInputBuffer();
void scanfInt(int *value);
void scanfText(char text[], int size);
void colorBackground(int backColor);
void colorForeground(int frontColor);
void registerProduct();
void listProducts();
void sellProduct();
void MainMenu();
void registerProduct();

/**
 * @brief Clears the terminal screen.
 *
 * This function sends ANSI escape codes to the terminal to clear the screen
 * and move the cursor to the home position (top-left corner).
 */
void ClearScreen()
{
   printf ("\033[2J\033[H");
}

/**
 * @brief Clears the input buffer by reading and discarding characters until a newline is encountered.
 * 
 * This function is useful for removing any residual input that may interfere with subsequent input operations.
 */
void clearInputBuffer() {
    while (getchar() != '\n'); // Limpa qualquer entrada residual
}

/**
 * @brief Reads an integer from standard input and stores it in the provided variable.
 *
 * This function uses `scanf` to read an integer from the standard input and stores
 * the value in the variable pointed to by `value`. After reading the input, it calls
 * `clearInputBuffer` to clear any remaining characters in the input buffer.
 *
 * @param value A pointer to an integer where the read value will be stored.
 */
void scanfInt(int *value) {
    if(value == NULL) {
        return;
    }
    scanf("%d", value);
    clearInputBuffer();
}

/**
 * @brief Reads a line of text from standard input and removes the trailing newline character.
 *
 * This function reads up to `size - 1` characters from standard input and stores them in the 
 * provided `text` array. It then replaces the newline character at the end of the input with 
 * a null terminator to ensure the string is properly terminated.
 *
 * @param text The array where the input text will be stored.
 * @param size The size of the `text` array.
 */
void scanfText(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

/**
 * @brief Sets the background color of the terminal.
 *
 * This function changes the background color of the terminal based on the
 * provided color code. It uses ANSI escape codes to set the color.
 *
 * @param backColor An integer representing the desired background color.
 *                  The valid values are:
 *                  - 0: Default
 *                  - 1: Black
 *                  - 2: Red
 *                  - 3: Green
 *                  - 4: Yellow
 *                  - 5: Blue
 *                  - 6: Magenta
 *                  - 7: Cyan
 *                  - 8: White
 *                  - 9: Gray
 *                  - 10: Light Red
 *                  - 11: Light Green
 *                  - 12: Light Yellow
 *                  - 13: Light Blue
 *                  - 14: Light Magenta
 *                  - 15: Light Cyan
 *                  - 16: Light White
 *
 * If an invalid color code is provided, the background color is set to default.
 */
void colorBackground(int backColor) {
    const char* codeColor = "";
    switch (backColor) {
        case 0:
            codeColor = "\033[0m"; //Default
            break;
        case 1:
            codeColor = "\033[40m"; //Black
            break;
        case 2:
            codeColor = "\033[41m"; //Red
            break;
        case 3:
            codeColor = "\033[42m"; //Green
            break;
        case 4:
            codeColor = "\033[43m"; //Yellow
            break;
        case 5:
            codeColor = "\033[44m"; //Blue
            break;
        case 6:
            codeColor = "\033[45m"; //Magenta
            break;
        case 7:
            codeColor = "\033[46m"; //Cyan
            break;
        case 8:
            codeColor = "\033[47m"; //White
            break;
        case 9:
            codeColor = "\033[100m"; //Gray
            break;
        case 10:
            codeColor = "\033[101m"; //Light Red
            break;
        case 11:
            codeColor = "\033[102m"; //Light Green
            break;
        case 12:
            codeColor = "\033[103m"; //Light Yellow
            break;
        case 13:
            codeColor = "\033[104m"; //Light Blue
            break;
        case 14:
            codeColor = "\033[105m"; //Light Magenta
            break;
        case 15:
            codeColor = "\033[106m"; //Light Cyan
            break;
        case 16:
            codeColor = "\033[107m"; //Light White
            break;
        default:
            codeColor = "\033[0m"; //Black (Default)
            break;
    }
    printf ("%s", codeColor);
    ClearScreen();
}

/**
 * @brief Sets the foreground color for terminal text output.
 *
 * This function changes the color of the text that follows it in the terminal.
 * It uses ANSI escape codes to set the color based on the provided `frontColor` value.
 *
 * @param frontColor An integer representing the desired foreground color:
 *                   The valid values are:
 *                   - 0: Default
 *                   - 1: Black
 *                   - 2: Red
 *                   - 3: Green
 *                   - 4: Yellow
 *                   - 5: Blue
 *                   - 6: Magenta
 *                   - 7: Cyan
 *                   - 8: White
 *                   - 9: Gray
 *                   - 10: Light Red
 *                   - 11: Light Green
 *                   - 12: Light Yellow
 *                   - 13: Light Blue
 *                   - 14: Light Magenta
 *                   - 15: Light Cyan
 *                   - 16: Light White
 *
 * If an invalid `frontColor` value is provided, the default color will be used.
 */
void colorForeground(int frontColor) {
    const char* codeColor = "";

    switch (frontColor) {
        case 0:
            codeColor = "\033[0m"; //Default
            break;
        case 1:
            codeColor = "\033[30m"; //Black
            break;
        case 2:
            codeColor = "\033[31m"; //Red
            break;
        case 3:
            codeColor = "\033[32m"; //Green
            break;
        case 4:
            codeColor = "\033[33m"; //Yellow
            break;
        case 5:
            codeColor = "\033[34m"; //Blue
            break;
        case 6:
            codeColor = "\033[35m"; //Magenta
            break;
        case 7:
            codeColor = "\033[36m"; //Cyan
            break;
        case 8:
            codeColor = "\033[37m"; //White
            break;
        case 9:
            codeColor = "\033[90m"; //Gray
            break;
        case 10:
            codeColor = "\033[91m"; //Light Red
            break;
        case 11:
            codeColor = "\033[92m"; //Light Green
            break;
        case 12:
            codeColor = "\033[93m"; //Light Yellow
            break;
        case 13:
            codeColor = "\033[94m"; //Light Blue
            break;
        case 14:
            codeColor = "\033[95m"; //Light Magenta
            break;
        case 15:
            codeColor = "\033[96m"; //Light Cyan
            break;
        case 16:
            codeColor = "\033[97m"; //Light White
            break;
        default:
            codeColor = "\033[0m"; //Black (Default)
            break;
    }

        printf ("%s", codeColor);
        ClearScreen();
}

void registerProduct()
{
    struct product productRef;
    int bufferInt = 0;

    ClearScreen();
    printf("Cadastro de Produtos\n\n");

    printf("Código do produto (Máximo 50 caracteres)\n\nPara retornar ao menu principal, digite 0\n\n");
    printf("Digite o código do produto: ");
    scanf("%d", &bufferInt);

    if(bufferInt == 0) {
        clearInputBuffer();
        MainMenu();
        return;
    }
    else if (bufferInt < 0) {
        printf("O código não pode ser 0 (zero). Tente outro código.\n");
        clearInputBuffer();
        getchar();
        registerProduct();
    }
    else {
        productRef.code = bufferInt;
    }
    
    clearInputBuffer();

    printf("Digite o nome do produto: ");
    fgets(productRef.name, sizeof(productRef.name), stdin);
    productRef.name[strcspn(productRef.name, "\n")] = '\0';

    printf("Digite o preco do produto: R$ ");
    scanf("%f", &productRef.price);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &productRef.amount);

    FILE *fileRef = fopen("products.bin", "a");
    fwrite(&productRef, sizeof(struct product), 1, fileRef);
    fclose(fileRef);

    printf("\nProduto cadastrado com sucesso!\nPressione qualquer tecla para voltar ao menu principal...\n");
    clearInputBuffer();
    getchar();
    MainMenu();
}

void listProducts()
{
    ClearScreen();
    printf("Listagem de Produtos\n\n");

    FILE *fileRef = fopen("products.bin", "r");
    struct product productRef;

    if (fileRef == NULL)
    {
        printf("Não há produtos cadastrados\n\nPressione qualquer tecla para voltar ao menu principal...\n");
        clearInputBuffer();
        getchar();
        MainMenu();
        return; // Encerra a função
    }

    while (fread(&productRef, sizeof(struct product), 1, fileRef))
    {
        printf("Código: %d\n", productRef.code);
        printf("Nome: %s\n", productRef.name);
        printf("Preço: R$ %.2f\n", productRef.price);
        printf("Quantidade: %d\n\n", productRef.amount);
    }

    printf("\nPressione qualquer tecla para voltar ao menu principal...");

    fclose(fileRef);

    clearInputBuffer();
    getchar();
    MainMenu();
}

void sellProduct() {
    ClearScreen();
    printf("Venda de Produtos\n\n");
    int op = 0;
    int code = 0;
    char name[50];
    char buffer [1];
    int saleAmount = 0;
    FILE *fileRef = fopen("products.bin", "r");
    struct product productRef;
    struct product productsList[0];

    if (fileRef == NULL) {
        printf("Não há produtos cadastrados\n\nPressione qualquer tecla para voltar ao menu principal...\n");
        clearInputBuffer();
        getchar();
        MainMenu();
        return; // Encerra a função
    }

    ClearScreen();
        printf("Venda de Produtos\n\nPara retornar ao menu principal, digite 0\n\n");

        while (1)
        {
            printf("Digite o código do produto: ");
            scanf("%d", &code);

            if(code == 0) {
                ClearScreen();
                clearInputBuffer();
                MainMenu();
                break;
            }

            int found = 0;
            rewind(fileRef); // Volta ao início do arquivo para nova busca

            while (fread(&productRef, sizeof(struct product), 1, fileRef))
            {
                if (productRef.code == code)
                {
                    printf("Produto encontrado!\n");
                    printf("Nome: %s\n", productRef.name);
                    printf("Preço: R$ %.2f\n", productRef.price);
                    printf("Quantidade: %d\n\n", productRef.amount);
                    found = 1;
                    break;
                }
            }

            if (found)
            {
                printf("Digite a quantidade de vendas: ");
                scanf("%d", &saleAmount);

                printf("Quantidade a ser vendida: %d\nConfirma? (S/N)", saleAmount);
                scanf("%s", buffer);

                if(buffer[0] == 'n' || buffer[0] == 'N') {
                    continue;
                }
                else if(buffer[0] != 's' && buffer[0] != 'S') {
                    printf("Opção inválida. Tente novamente.\n");
                    continue;
                }

                if (saleAmount <= productRef.amount)
                {
                    productRef.amount -= saleAmount;
                    FILE *tempFile = fopen("temp.bin", "w");
                    rewind(fileRef); // Volta ao início do arquivo original

                    struct product tempProduct;
                    while (fread(&tempProduct, sizeof(struct product), 1, fileRef))
                    {
                        if (tempProduct.code == productRef.code)
                        {
                            tempProduct.amount = productRef.amount;
                        }
                        fwrite(&tempProduct, sizeof(struct product), 1, tempFile);
                    }

                    fclose(fileRef);
                    fclose(tempFile);

                    remove("products.bin");
                    rename("temp.bin", "products.bin");

                    printf("Venda realizada com sucesso!\n");
                }
                else
                {
                    printf("Quantidade insuficiente em estoque. Tente novamente.\n");
                    continue;
                }
                break; // Sai do loop se o produto foi encontrado
            }
            else
            {
                printf("Produto não encontrado. Tente novamente.\n");
            }
        }
}

void MainMenu()
{
    ClearScreen();
    colorBackground(5);
    colorForeground(16);

    int op = 0;

    printf("** Sistema Gerenciamento de Loja **\n\n");
    printf("1 - Cadastro de Produtos\n");
    printf("2 - Consulta de Produtos\n");
    printf("3 - Venda de Produtos\n");
    printf("4 - Relatorios\n");
    printf("5 - Sair\n\n");

    printf("Digite a opcao desejada: ");

    scanf("%d", &op);

    switch (op) {
        case 1:
            registerProduct();
            break;
        case 2:
            listProducts();
            break;
        case 3:
            sellProduct();
            break;
        case 4:
            MainMenu();
            break;
        case 5:
            printf("Saindo...\n");
            ClearScreen();
            colorBackground(0);
            colorForeground(0);
            return;
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }
};

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    MainMenu();
    return 0;
}