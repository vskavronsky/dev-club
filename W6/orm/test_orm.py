import unittest
from models import Category, Item


class TestCategory(unittest.TestCase):
    def setUp(self):
        self.category = Category('Test')

    def test_constructor(self):
        category2 = Category()

        self.assertIsNone(category2.title)
        self.assertIsNone(category2.id)
        self.assertEqual(category2._changed_fields, set())

        self.assertEqual(self.category.title, 'Test')
        self.assertIsNone(self.category.id)
        self.assertEqual(self.category._changed_fields, set())

    def test_setter(self):
        self.category.title = 'Test2'
        test_set = {'title'}
        self.assertEqual(self.category.title, 'Test2')
        self.assertEqual(self.category._changed_fields, test_set)

    def test_save(self):
        self.category.save()
        str_category = f'category({self.category.id})'

        self.assertIsNotNone(self.category.id)
        self.assertEqual(str(self.category), str_category)
        self.assertEqual(repr(self.category), str_category)

    def test_update_get(self):
        self.category.title = 'Test3'
        self.category.save()
        self.assertEqual(Category.get(self.category.id).title, 'Test3')

    def test_all(self):
        test_list = Category.all()
        test_class = self.category.__class__

        for cat in test_list:
            self.assertIs(type(cat), test_class)

    def tearDown(self):
        self.assertIsNone(Category.delete(self.category.id))


class TestItem(unittest.TestCase):
    def setUp(self):
        self.category1 = Category('ParentTest1')
        self.category1.save()
        self.category2 = Category('ParentTest2')
        self.category2.save()
        self.item = Item('ChildTest', 1000, self.category1.id)

    def test_constructor(self):
        item2 = Item()

        self.assertIsNone(item2.title)
        self.assertIsNone(item2.price)
        self.assertIsNone(item2.category_id)
        self.assertIsNone(item2.id)
        self.assertEqual(item2._changed_fields, set())

        self.assertEqual(self.item.title, 'ChildTest')
        self.assertIsNone(item2.price, 1000)
        self.assertIsNone(item2.category_id, self.category1.id)
        self.assertIsNone(self.item.id)
        self.assertEqual(self.item._changed_fields, set())

    def test_setter(self):
        self.item.title = 'ChildTest2'
        test_set = {'title'}
        self.assertEqual(self.item.title, 'ChildTest2')
        self.assertEqual(self.item._changed_fields, test_set)

        self.item.price = 2000
        test_set = {'price', 'title'}
        self.assertEqual(self.item.price, 2000)
        self.assertEqual(self.item._changed_fields, test_set)

        self.item.category_id = 5
        test_set = {'category_id', 'price', 'title'}
        self.assertEqual(self.item.category_id, 5)
        self.assertEqual(self.item._changed_fields, test_set)

    def test_save(self):
        self.item.save()
        str_item = f'item({self.item.id})'

        self.assertIsNotNone(self.item.id)
        self.assertEqual(str(self.item), str_item)
        self.assertEqual(repr(self.item), str_item)

    def test_update_get(self):
        self.item.title = 'ChildTest3'
        self.item.save()
        self.assertEqual(Item.get(self.item.id).title, 'ChildTest3')

        self.item.price = 3000
        self.item.save()
        self.assertEqual(Item.get(self.item.id).price, 3000)

        self.item.category_id = self.category2.id
        self.item.save()
        self.assertEqual(Item.get(self.item.id).category_id, self.category2.id)

    def test_all(self):
        test_list = Item.all()
        test_class = self.item.__class__

        for item in test_list:
            self.assertIs(type(item), test_class)

    def tearDown(self):
        self.assertIsNone(Item.delete(self.item.id))

    def doCleanups(self):
        Category.delete(self.category1.id)
        Category.delete(self.category2.id)


if __name__ == '__main__':
    unittest.main()
