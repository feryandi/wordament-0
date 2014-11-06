/*
 *    strmap version 2.0.1
 *
 *    ANSI C hash table for strings.
 *
 *	  Version history:
 *	  1.0.0 - initial release
 *	  2.0.0 - changed function prefix from strmap to sm to ensure
 *	      ANSI C compatibility 
 *	  2.0.1 - improved documentation 
 *
 *    strmap.c
 *
 *    Copyright (c) 2009, 2011, 2013 Per Ola Kristensson.
 *
 *    Per Ola Kristensson <pok21@cam.ac.uk> 
 *    Inference Group, Department of Physics
 *    University of Cambridge
 *    Cavendish Laboratory
 *    JJ Thomson Avenue
 *    CB3 0HE Cambridge
 *    United Kingdom
 *
 *    strmap is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    strmap is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with strmap.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "strmap.h"

typedef struct Pair Pair;

typedef struct Bucket Bucket;

struct Pair {
	char *key;
	char *value;
};

struct Bucket {
	unsigned int count;
	Pair *pairs;
};

struct StrMap {
	unsigned int count;
	Bucket *buckets;
};

static Pair * get_pair(Bucket *bucket, const char *key);
static unsigned long hash(const char *str);

StrMap * sm_new(unsigned int capacity)
{
	StrMap *map;
	
	map = malloc(sizeof(StrMap));
	if (map == NULL) {
		return NULL;
	}
	map->count = capacity;
	map->buckets = malloc(map->count * sizeof(Bucket));
	if (map->buckets == NULL) {
		free(map);
		return NULL;
	}
	memset(map->buckets, 0, map->count * sizeof(Bucket));
	return map;
}
int sm_get(const StrMap *map, const char *key, char *out_buf, unsigned int n_out_buf)
{
	unsigned int index;
	Bucket *bucket;
	Pair *pair;

	if (map == NULL) {
		return 0;
	}
	if (key == NULL) {
		return 0;
	}
	index = hash(key) % map->count;
	bucket = &(map->buckets[index]);
	pair = get_pair(bucket, key);
	if (pair == NULL) {
		return 0;
	}
	if (out_buf == NULL && n_out_buf == 0) {
		return strlen(pair->value) + 1;
	}
	if (out_buf == NULL) {
		return 0;
	}
	if (strlen(pair->value) >= n_out_buf) {
		return 0;
	}
	strcpy(out_buf, pair->value);
	return 1;
}
int sm_put(StrMap *map, const char *key, const char *value)
{
	unsigned int key_len, value_len, index;
	Bucket *bucket;
	Pair *tmp_pairs, *pair;
	char *tmp_value;
	char *new_key, *new_value;

	if (map == NULL) {
		return 0;
	}
	if (key == NULL || value == NULL) {
		return 0;
	}
	key_len = strlen(key);
	value_len = strlen(value);
	/* Get a pointer to the bucket the key string hashes to */
	index = hash(key) % map->count;
	bucket = &(map->buckets[index]);
	/* Check if we can handle insertion by simply replacing
	 * an existing value in a key-value pair in the bucket.
	 */
	if ((pair = get_pair(bucket, key)) != NULL) {
		/* The bucket contains a pair that matches the provided key,
		 * change the value for that pair to the new value.
		 */
		if (strlen(pair->value) < value_len) {
			/* If the new value is larger than the old value, re-allocate
			 * space for the new larger value.
			 */
			tmp_value = realloc(pair->value, (value_len + 1) * sizeof(char));
			if (tmp_value == NULL) {
				return 0;
			}
			pair->value = tmp_value;
		}
		/* Copy the new value into the pair that matches the key */
		strcpy(pair->value, value);
		return 1;
	}
	/* Allocate space for a new key and value */
	new_key = malloc((key_len + 1) * sizeof(char));
	if (new_key == NULL) {
		return 0;
	}
	new_value = malloc((value_len + 1) * sizeof(char));
	if (new_value == NULL) {
		free(new_key);
		return 0;
	}
	/* Create a key-value pair */
	if (bucket->count == 0) {
		/* The bucket is empty, lazily allocate space for a single
		 * key-value pair.
		 */
		bucket->pairs = malloc(sizeof(Pair));
		if (bucket->pairs == NULL) {
			free(new_key);
			free(new_value);
			return 0;
		}
		bucket->count = 1;
	}
	else {
		/* The bucket wasn't empty but no pair existed that matches the provided
		 * key, so create a new key-value pair.
		 */
		tmp_pairs = realloc(bucket->pairs, (bucket->count + 1) * sizeof(Pair));
		if (tmp_pairs == NULL) {
			free(new_key);
			free(new_value);
			return 0;
		}
		bucket->pairs = tmp_pairs;
		bucket->count++;
	}
	/* Get the last pair in the chain for the bucket */
	pair = &(bucket->pairs[bucket->count - 1]);
	pair->key = new_key;
	pair->value = new_value;
	/* Copy the key and its value into the key-value pair */
	strcpy(pair->key, key);
	strcpy(pair->value, value);
	return 1;
}
/*
 * Returns a pair from the bucket that matches the provided key,
 * or null if no such pair exist.
 */
static Pair * get_pair(Bucket *bucket, const char *key)
{
	unsigned int i, n;
	Pair *pair;

	n = bucket->count;
	if (n == 0) {
		return NULL;
	}
	pair = bucket->pairs;
	i = 0;
	while (i < n) {
		if (pair->key != NULL && pair->value != NULL) {
			if (strcmp(pair->key, key) == 0) {
				return pair;
			}
		}
		pair++;
		i++;
	}
	return NULL;
}

/*
 * Returns a hash code for the provided string.
 */
static unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}

 int Map (char key)
 {
	StrMap *sm;
	char buf[255];
	int result;
	int val;

	sm = sm_new(30);
	if (sm != NULL) {
	sm_put(sm, "E", "1");
	sm_put(sm, "A", "11");
	sm_put(sm, "I", "11");
	sm_put(sm, "N", "11");
	sm_put(sm, "O", "11");
	sm_put(sm, "R", "11");
	sm_put(sm, "S", "11");
	sm_put(sm, "T", "11");
	sm_put(sm, "C", "111");
	sm_put(sm, "D", "111");
	sm_put(sm, "L", "111");
	sm_put(sm, "G", "1111");
	sm_put(sm, "H", "1111");
	sm_put(sm, "M", "1111");
	sm_put(sm, "P", "1111");
	sm_put(sm, "U", "1111");
	sm_put(sm, "B", "11111");
	sm_put(sm, "F", "11111");
	sm_put(sm, "Y", "11111");
	sm_put(sm, "K", "111111");
	sm_put(sm, "V", "111111");
	sm_put(sm, "W", "111111");
	sm_put(sm, "Z", "11111111");
	sm_put(sm, "X", "111111111");
	sm_put(sm, "Q", "1111111111");
	sm_put(sm, "J", "1111111111");

	result = sm_get(sm, &key, buf, sizeof(buf));
	if (result != 0) {
	val = strlen(buf);
	return val;
	}
	}
 }
 
 void Score(Stack *S, int *score)
 {
	int sum=0;
	int count=0;
	char X;
	while (!IsEmpty(*S)) {
		Pop(S,&X);
		count++;
		sum = sum+Map(X);
		}
	score = sum*count;
	if (count>=10)
		score += 100;
 }
 