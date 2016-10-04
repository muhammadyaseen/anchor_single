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


#ifdef __cplusplus
}
#endif

#endif /* USART_QUEUE_H_ */
