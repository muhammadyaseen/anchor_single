/*
 * encryption.c
 *
 *  Created on: 6 Apr 2015
 *      Author: rm
 */

#include "encryption.h"

void random_select(uint8* key, uint8* key_index)
{
	uint8 key_index_temp = *key_index;
	*key_index = (key_index_temp+4) & 0x1f; // %64
	for(uint8 i =0; i<KEY_LEN ; i++)
		*(key+i) = random_set[key_index_temp+i];
}

uint32 encrypt_rc4(uint8* key_arr, uint32 data)
{

	uint32 rc4_out; 	// 	rc4 output
	uint8 data_arr[KEY_LEN];	// 	array to store data
	uint8 out_arr[KEY_LEN];	// 	array to store data

	uint8 S[256];		//
	uint8 T[256];

	uint8 n , t;
	uint8 temp;

	uint16 i,j;

	data_arr[0] =  data 		& 0xff;
	data_arr[1] = (data >> 8  )	& 0xff;
	data_arr[2] = (data >> 16 )	& 0xff;
	data_arr[3] = (data >> 24 )	& 0xff;

	for (i=0 ; i<256 ; i++)
	{
		S[i]= i & 0xff;
		T[i]= *(key_arr+(i & 0X03));
	}

	j=0;

	for(i=0;i<256;i++)
	{
		j=(j + S[i] + T[i]) & 0xff;
		temp=S[i];
		S[i]=S[j];
		S[j]=temp;
	}

	i=0;
	j=0;

	for(n=1;n < KEY_LEN; n++)
	{
		i= i + 1;
		j=(j + S[i]) & 0xff;
		temp=S[i];
		S[i]=S[j];
		S[j]=temp;
		t = (S[i] + S[j]) & 0xff;

		out_arr[n] = (S[t] ^ data_arr[n]);
	}

	rc4_out = out_arr[0] + (out_arr[1] << 8) +(out_arr[2] << 16) + (out_arr[3] << 24) ;

	return rc4_out;

}
