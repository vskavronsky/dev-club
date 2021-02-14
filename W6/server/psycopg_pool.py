import psycopg2
from psycopg2 import pool

try:
    postgreSQL_pool = psycopg2.pool.SimpleConnectionPool(1, 20,
                                                         dbname='test',
                                                         user='vitalii',
                                                         password='0000',
                                                         host='127.0.0.1',
                                                         port='5432')
    
    if postgreSQL_pool:
        print('Connection to db was successful!')
        
    ps_conn = postgreSQL_pool.getconn()
    
    if ps_conn:
        print('Successfully recived connection from connection pool!')
        ps_cursor = ps_conn.cursor()
        ps_cursor.execute("SELECT * FROM polls_choice;")
        records = ps_cursor.fetchall()
        
        print ("Displaying rows from test table:")
        for row in records:
            print(row)
                
        ps_cursor.close()
        
        postgreSQL_pool.putconn(ps_conn)
        print("Put away a PostgreSQL connection!")

except (Exception, psycopg2.DatabaseError) as error:
    print('Error while connecting to postgreSQL', error)
    
finally:
    if postgreSQL_pool:
        postgreSQL_pool.closeall()
    print("PostgreSQL connection pool is closed!")
    