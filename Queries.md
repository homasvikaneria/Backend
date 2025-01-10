### **1. Create the Database and Collections**

create a new database called `CodingGita`. Inside this database, create two collections: `students` and `courses`.

**Step 1: Create the database**
```js
use codinggita  // Switch to the CodingGita database if that db already exist. If it doesn't exist, MongoDB will create it automatically.
```
**Step 2: Create the `students` collection**
```js
db.createCollection("students");
```

**Step 3: Create the `courses` collection**
```js
db.createCollection("courses");
```
We have created an empty database with two collections

### **2. Insert Data**
**Step 1: Insert data into the `students` collection**
```js
db.students.insertMany([
  { 
    "name": "Jenil",
    "rollNumber": 101,
    "department": "Computer Science",
    "year": 2,
    "coursesEnrolled": ["CS101", "CS102"]
  },
  { 
    "name": "Mahir",
    "rollNumber": 102,
    "department": "Computer Science",
    "year": 2,
    "coursesEnrolled": ["CS101", "CS103"]
  },
  { 
    "name": "Arjun",
    "rollNumber": 103,
    "department": "Electrical Engineering",
    "year": 3,
    "coursesEnrolled": ["EE101", "EE102"]
  }
]);
```

**Step 2: Insert data into the `courses` collection**
```js
db.courses.insertMany([
  { 
    "courseCode": "CS101", 
    "courseName": "Introduction to Programming", 
    "credits": 3, 
    "instructor": "Prof. Sharma" 
  },
  { 
    "courseCode": "CS102", 
    "courseName": "Data Structures", 
    "credits": 3, 
    "instructor": "Prof. Gupta" 
  },
  { 
    "courseCode": "CS103", 
    "courseName": "Algorithms", 
    "credits": 3, 
    "instructor": "Prof. Kapoor" 
  },
  { 
    "courseCode": "EE101", 
    "courseName": "Basic Electrical Engineering", 
    "credits": 4, 
    "instructor": "Prof. Verma" 
  },
  { 
    "courseCode": "EE102", 
    "courseName": "Circuit Theory", 
    "credits": 4, 
    "instructor": "Prof. Yadav" 
  }
]);
```
#### **3. Querying Data**

Now, let's perform some queries to fetch data based on different conditions.

**Step 1: Query students based on department**
If we want to find all students in the **Computer Science** department, we can use the `find` method with a query filter.

```js
db.students.find({ "department": "Computer Science" });
```

This query will return all students who belong to the **Computer Science** department.

**Step 2: Query students based on year**
If we want to find students who are in **year 2**, we can query the `students` collection like this:

```js
db.students.find({ "year": 2 });
```

This will return all students who are in the second year.

**Step 3: Query students by course enrollment**
Let’s say you want to find all students who are enrolled in **CS101**. You can perform the following query:

```js
db.students.find({ "coursesEnrolled": "CS101" });
```

This query will return all students who are enrolled in the **CS101** course.

---

#### **4. Updating Data**

Updating data in MongoDB is easy with the `updateOne` and `updateMany` methods. Let’s go through some examples of how to update data.

**Step 1: Update a student’s courses**
Let’s say **Arjun** wants to update his courses and add the **CS102** course to his list of enrolled courses.

```js
db.students.updateOne(
  { "name": "Arjun" },
  { $push: { "coursesEnrolled": "CS102" } }
);
```

This command will update **Arjun’s** document by pushing **CS102** into his `coursesEnrolled` array.

**Step 2: Update a course instructor**
If **Prof. Gupta** is no longer teaching **Data Structures** (CS102), we can update the instructor for that course.

```js
db.courses.updateOne(
  { "courseCode": "CS102" },
  { $set: { "instructor": "Prof. Mehta" } }
);
```

This query updates the `instructor` field for the course **CS102** to **Prof. Mehta**.

---

#### **5. Deleting Data**

Deleting data in MongoDB is straightforward. You can use the `deleteOne` or `deleteMany` methods to remove documents.

**Step 1: Delete a student record**
If we want to delete **Arjun’s** student record from the database, we can do so with the following command:

```js
db.students.deleteOne({ "name": "Arjun" });
```

This will delete the document where the `name` field is **Arjun**.

**Step 2: Delete all students from a specific department**
Let’s say we want to remove all students from the **Electrical Engineering** department:

```js
db.students.deleteMany({ "department": "Electrical Engineering" });
```

This will delete all students in the **Electrical Engineering** department.

---

diff b/w $set and $push
Query all students in the database and print out their names and enrolled subjects.
