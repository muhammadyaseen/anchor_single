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

int QueueFull( USART_QueueTypedef * q )
{
	return ( ((q->pWR + 1) % QUEUE_SIZE) == q->pRD );
}

int QueueEmpty( USART_QueueTypedef * q)
{
	return ( q->pWR == q->pRD );
}

int Enqueue( USART_QueueTypedef * q, uint8_t * data)
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

int Dequeue( USART_QueueTypedef * q, uint8_t * data)
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


#ifdef __cplusplus
}
#endif

#endif /* USART_QUEUE_H_ */
