LOAD 'forbid_truncate';

CREATE TEMP TABLE test (a int, b char(20));

INSERT INTO test VALUES(generate_series(1, 10), 'aaa');

-- forbid truncate  this command is forbidden
TRUNCATE TABLE test;

-- No change
SELECT * FROM test;


-- DDL command function correctly
ALTER TABLE test ADD
	foo VARCHAR(30)
;

ALTER TABLE test ALTER COLUMN
	foo TYPE VARCHAR(20)
;

ALTER TABLE test DROP
	foo
;

ALTER TABLE test
RENAME TO test2;

DROP TABLE test2;
