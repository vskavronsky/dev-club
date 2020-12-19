-- 1. Создать юзера shop и дать ему полный доступ к БД shop.
CREATE ROLE shop LOGIN CREATEDB PASSWORD '0000';

-- 2. Создать базу данных shop.
CREATE DATABASE shop WITH OWNER=shop ENCODING='UTF8';

-- 4. Создать таблицу для хранения категорий (хранить название).
CREATE TABLE "category" (
    category_id SERIAL PRIMARY KEY NOT NULL,
    category_title VARCHAR(256) NOT NULL
    );

-- 5. Добавить несколько категорий.
INSERT INTO "category" (category_title) VALUES ('cars'), ('trucks'), ('airplanes');

-- 6. Создать таблицу для хранения товаров (название, категория, цена).
CREATE TABLE "item" (
    item_id SERIAL PRIMARY KEY NOT NULL,
    item_title VARCHAR(256) NOT NULL,
    item_price DECIMAL(8,2) NOT NULL,
    category_id INTEGER NOT NULL
    );

-- 7. Внести несколько товаров по цене 1.00
INSERT INTO "item" (item_title, item_price, category_id) VALUES
    ('BMW', 1.00, 1),
    ('AUDI', 49999.99, 1),
    ('IVECO', 1.00, 2),
    ('MAN', 59999.98, 2),
    ('Boeing', 1.00, 3),
    ('Airbus', 699999.97, 3);
    
-- 8. Обновить цену первого товара — 3.50
UPDATE "item" SET item_price = 3.50 WHERE item_id = 1;

-- 9. Увеличить цену всех товаров на 10%.
UPDATE "item" SET item_price = item_price * 1.1;

-- 10. Удалить товар № 2.
DELETE FROM "item" WHERE item_id = 2;

-- 11. Выбрать все товары с сортировкой по названию.
SELECT * FROM "item" ORDER BY item_title;

-- 12. Выбрать все товары с сортировкой по убыванию цены.
SELECT * FROM "item" ORDER BY item_price DESC;

-- 13. Выбрать 3 самых дорогих товара.
SELECT * FROM "item" ORDER BY item_price DESC LIMIT 3;

-- 14. Выбрать 3 самых дешевых товара.
SELECT * FROM "item" ORDER BY item_price ASC LIMIT 3;

-- 15. Выбрать вторую тройку самых дорогих товаров (с 4 по 6).
SELECT * FROM "item" ORDER BY item_price DESC LIMIT 3 OFFSET 3;

-- 16. Выбрать наименование самого дорогого товара.
SELECT item_title FROM "item" ORDER BY item_price DESC LIMIT 1;

-- 17. Выбрать наименование самого дешевого товара.
SELECT item_title FROM "item" ORDER BY item_price ASC LIMIT 1;

-- 18. Выбрать количество всех товаров.
SELECT COUNT(*) FROM "item";

-- 19. Выбрать среднюю цену всех товаров.
SELECT AVG(item_price)::DECIMAL(8,2) FROM "item";
