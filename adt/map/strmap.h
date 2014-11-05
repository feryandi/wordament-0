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
 *    strmap.h
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
#ifndef _STRMAP_H_
#define _STRMAP_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <string.h>

typedef struct StrMap StrMap;

/*
 * This callback function is called once per key-value when iterating over
 * all keys associated to values.
 *
 * Parameters:
 *
 * key: A pointer to a null-terminated C string. The string must not
 * be modified by the client.
 *
 * value: A pointer to a null-terminated C string. The string must
 * not be modified by the client.
 *
 * obj: A pointer to a client-specific object. This parameter may be
 * null.
 *
 * Return value: None.
 */
typedef void(*sm_enum_func)(const char *key, const char *value, const void *obj);

/*
 * Creates a string map.
 *
 * Parameters:
 *
 * capacity: The number of top-level slots this string map
 * should allocate. This parameter must be > 0.
 *
 * Return value: A pointer to a string map object, 
 * or null if a new string map could not be allocated.
 */
StrMap * sm_new(unsigned int capacity);

/*
 * Releases all memory held by a string map object.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 * If the supplied string map has been previously released, the
 * behaviour of this function is undefined.
 *
 * Return value: None.
 */
int sm_get(const StrMap *map, const char *key, char *out_buf, unsigned int n_out_buf);

/*
 * Queries the existence of a key.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 *
 * key: A pointer to a null-terminated C string. This parameter cannot
 * be null.
 *
 * Return value: 1 if the key exists, 0 otherwise.
 */

int sm_put(StrMap *map, const char *key, const char *value);

/*
 * Returns the number of associations between keys and values.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 *
 * Return value: The number of associations between keys and values.
 */
 
 int Map (char key);
 
 void Score(Stack *S, int *score);
 
#ifdef __cplusplus
}
#endif

#endif