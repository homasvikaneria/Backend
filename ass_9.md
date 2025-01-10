## **Assignment: Building the "CodingGita Students" Database**

## **6. Practice Assignments**

**Task 1: Create a "CodingGita Students" database**

Create a new MongoDB database called `CodingGita`. Add two collections:


```js
use codinggita 
db.createCollection("students");
db.createCollection("courses");
```

Insert sample data into both collections.

 `students`: Name, roll number, department, year, courses enrolled.

```js
db.students.insertMany([
  { 
    "name": "Esha",
    "rollNumber": 101,
    "department": "Computer Science",
    "year": 1,
    "coursesEnrolled": ["CS101", "CS102"]
  },
  { 
    "name": "Ishika",
    "rollNumber": 102,
    "department": "Computer Science",
    "year": 2,
    "coursesEnrolled": ["CS101", "CS103"]
  },
  { 
    "name": "Sweta",
    "rollNumber": 103,
    "department": "Mechanical Engineering",
    "year": 3,
    "coursesEnrolled": ["EE101", "EE102"]
  }
]);
```

 `courses`: Course code, name, credits, instructor.
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
]);
```

**Task 2: Perform CRUD operations**
- Add a few more students and courses to the database.
```js
db.students.insertMany([
    { 
    "name": "Shivani",
    "rollNumber": 104,
    "department": "Mechanical Engineering",
    "year": 3,
    "coursesEnrolled": ["EE101", "EE102"]
  }
  { 
    "name": "Umang",
    "rollNumber": 105,
    "department": "Mechanical Engineering",
    "year": 3,
    "coursesEnrolled": ["EE101", "EE102"]
  }
]);
```
```js
  db.courses.insertMany([
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
- Query data based on:
  - Department (e.g., "Computer Science").
  ```js
  db.students.find({"department":"Computer Science"})
  ```
  - Year (e.g., "2").
  ```js
  db.students.find({"year":2})
  ```
  - Courses enrolled (e.g., "CS101").
  ```js
  db.courses.courseCode({"courseCode":"CS101"})
  ```
- Update the courses for a specific student (e.g., adding a new course).
  ```js
  db.students.updateOne(
  { "name": "Esha" },
  { $push: { "coursesEnrolled": "CS103" } } // Add "CS103" to Esha's enrolled courses
);
 ```
 ```js
  db.courses.updateOne(
  { "courseCode": "CS101" },
  { $set: { "instructor": "Dr. Sharma" } }
);
```
- Delete a student or course from the database.

  ```js
  db.students.deleteOne({ "name": "Sweta" });
  ```
  ```js
  db.courses.deleteOne({ "courseCode": "CS103" });
  ```