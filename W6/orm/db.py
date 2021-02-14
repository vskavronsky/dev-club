import psycopg2
from psycopg2 import pool
from psycopg2.extras import RealDictCursor
from contextlib import contextmanager


ALL_STMT = 'SELECT * FROM {tablename}'
ONE_STMT = 'SELECT * FROM {tablename} WHERE id = %s'
INSERT_STMT = 'INSERT INTO {tablename} ({fields}) VALUES ({values}) RETURNING id'
UPDATE_STMT = 'UPDATE {tablename} SET {changed_fields} WHERE id = %s'
DELETE_STMT = 'DELETE FROM {tablename} WHERE id = %s'


connection_pool = psycopg2.pool.SimpleConnectionPool(
    1, 20,
    dbname = 'shop',
    user = 'admin',
    password = '0000',
    host = '127.0.0.1',
    port = '5432'    
) 

@contextmanager
def get_cursor():    
    conn = connection_pool.getconn()
    try:
        yield conn.cursor(cursor_factory=RealDictCursor)
        conn.commit()
    finally:
        connection_pool.putconn(conn)
        