#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_usart.h>


void assert_failed(uint8_t* file, uint32_t line) { }


void USART_Config()
{
    GPIO_InitTypeDef gpio;
    USART_InitTypeDef usart;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    gpio.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_1;
    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpio);

    gpio.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_0;
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &gpio);

    USART_StructInit(&usart);
    usart.USART_BaudRate = 115200;
    usart.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    usart.USART_WordLength = USART_WordLength_8b;
    usart.USART_StopBits = USART_StopBits_1;
    usart.USART_Parity = USART_Parity_No;
    usart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART2, &usart);
    USART_Cmd(USART2, ENABLE);


}

void usart_putc(char ch)
{
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
    USART2->DR = (ch & 0xff);
}
void usart_send(const char*s)
{
    while(*s)
        usart_putc(*s++);
}

int main(void)
{
    USART_Config();
    usart_send("Hello World!");
    while(1){}
}

