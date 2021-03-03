#ifndef RESULT_H
#define RESULT_H

typedef enum ResultType {
	RESULT_OK,
	RESULT_ERR,
} ResultType;

#define result_type(ok, err) struct { \
		union { \
			ok ok_value; \
			err err_value; \
		} value; \
		ResultType type; \
	}

#define result_ok(v) { .value = v, .type = RESULT_OK }
#define result_err(v) { .value = v, .type = RESULT_ERR }

#define is_ok(result) (result.type == RESULT_OK)
#define is_err(result) (result.type == RESULT_ERR)

#endif // RESULT_H
