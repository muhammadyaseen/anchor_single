#ifndef USART_QUEUE_H_
#define USART_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define QUEUE_SIZE 20

typedef struct USART_Queue {

	uint16_t pWR, pRD;
	uint8_t q[QUEUE_SIZE];

} USART_QueueTypedef;

int QueueFull(__IO USART_QueueTypedef * q )
{
	return ( ((q->pWR + 1) % QUEUE_SIZE) == q->pRD );
}

int QueueEmpty(__IO USART_QueueTypedef * q)
{
	return ( q->pWR == q->pRD );
}

int Enqueue(__IO USART_QueueTypedef * q, uint8_t * data)
{
	if (QueueFull(q))
		return 0;
	else
	{
		q->q[q->pWR] = *data;
		q->pWR = ( q->pWR + 1 == QUEUE_SIZE ) ? 0 : q->pWR + 1;
	}

	return 1;
}

int Dequeue(__IO USART_QueueTypedef * q, uint8_t * data)
{
	if (QueueEmpty(q))
		return 0;
	else
	{
		*data = q->q[q->pRD];
		q->pRD = ( (q->pRD + 1 ) == QUEUE_SIZE ) ? 0: q->pRD + 1;
	}

	return 1;
}

__IO USART_QueueTypedef txQueue;
__IO USART_QueueTypedef rxQueue;

__IO uint8_t TxPrime = 0;
__IO uint8_t RxOverflow = 0;


int USART_Get(void)
{
	uint8_t data;

	while( ! Dequeue(&rxQueue, &data) );

	return data;
}

void USART_Put(int c)
{
	while ( ! Enqueue(&txQueue, (uint8_t *)&c) );

	if (!TxPrime)
	{
		TxPrime = 1;
		USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
	}

}

void USART_Puts(char * str, int len)
{
	int idx = 0;

	while( idx <= (len - 1) )
	{
		USART_Put( (int)( str[idx++] ) );
	}
}

void USART_Gets(char * buf, int len)
{
	int idx = 0;

	while( idx <= (len - 1) )
	{
		buf[idx++] = USART_Get();
	}
}

void USART3_IRQHandler(void)
{
	if ( USART_GetITStatus(USART3, USART_IT_RXNE) != RESET )
	{
		uint8_t data;

		data = USART_ReceiveData(USART3) & 0xFF;

		if ( ! Enqueue(&rxQueue, (uint8_t *)&data) )
			RxOverflow = 1;
	}

	if ( USART_GetITStatus(USART3, USART_IT_TXE) != RESET )
	{
		uint8 data;

		if ( Dequeue( &txQueue, (uint8_t *)&data) )
		{
			USART_SendData(USART3, data);
		}
		else
		{
			USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
			TxPrime = 0;
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif /* USART_QUEUE_H_ */
