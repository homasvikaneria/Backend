## **6.  Practice Tasks**

```js
use studentinfo
db.createCollection("students");
db.createCollection("courses");  
```
Task 1: Add multiple students
Insert at least 5 students into the students collection with unique roll numbers, names, departments, years, and subjects enrolled.
```js
db.students.insertMany([
  { 
    "name": "ishika",
    "rollNumber": 101,
    "department": "Computer Science",
    "year": 2,
    "subjectsEnrolled": ["React", "NodeJS", "MongoDB"]
  },
  { 
    "name": "Hetvi",
    "rollNumber": 102,
    "department": "Computer Science",
    "year": 2,
    "subjectsEnrolled": ["React", "NodeJS"]
  },
  { 
    "name": "Heer",
    "rollNumber": 103,
    "department": "Electrical Engineering",
    "year": 3,
    "subjectsEnrolled": ["Circuit Theory", "Electrical Machines"]
  }
    { 
    "name": "Sakshi",
    "rollNumber": 104,
    "department": "Electrical Engineering",
    "year": 3,
    "subjectsEnrolled": ["Circuit Theory", "Electrical Machines"]
  }
    { 
    "name": "Aman",
    "rollNumber": 105,
    "department": "Electrical Engineering",
    "year": 3,
    "subjectsEnrolled": ["NodeJS ", "React"]
  }
]);
```

Task 2: Add multiple subjects
Insert 4 subjects into the subjects collection, each with 3 to 5 topics.
```js
db.courses.insertMany([
  { 
    "subjectName": "React",
    "topics": [
      "JSX", 
      "Components", 
      "State", 
      "Props", 
      "Hooks"
    ]
  },
  { 
    "subjectName": "NodeJS", 
    "topics": [
      "Modules", 
      "Express", 
      "File System", 
      "Asynchronous Programming"
    ]
  },
  { 
    "subjectName": "MongoDB", 
    "topics": [
      "Database Design", 
      "CRUD Operations", 
      "Aggregation", 
      "Indexes"
    ]
  }
]);
```

Task 3: Query students based on subject enrollment
```js
db.students.find({
    "subjectsEnrolled": "NodeJS"
    });
```
Query the students collection to find all students who are enrolled in NodeJS.
```js
db.courses.find({
    "subjectname":"NodeJS"
})
```

Task 4: Add a new topic to a subject
Add a new topic to the NodeJS subject.
```js
db.courses.updateOne({
    "subjectName":"NodeJS"},{
        $push:{
            "topics": "RESTful API"
        }
    }
)
```

Task 5: Query subjects with multiple topics
Query the subjects collection to find subjects that contain at least 4 topics.
```js
db.courses.find({
    "topics":{"$size":4}
})
```

Task 6: Update student enrollment
Add the subject "React Native" to Sakshi's subjects.
```js
db.students.updateOne({
    "name": "Sakshi"},{
        $push:{
            "subjectsEnrolled": "React Native"
        }
})
```

Task 7: Query all students
Query all students in the database and print out their names and enrolled subjects.
```js
db.students.find(
  {}, // Query to select all documents
  { name: 1, coursesEnrolled: 1, _id: 0 } // Projection to include name and subjectsEnrolled, 
);

```


Task 8: Update multiple students' year
Update the year for all students in the Computer Science department to year 3.
```js
db.students.updateMany({
    "department":"Computer Science"},{
        $set:{
            "year":3
    }
})
```

Task 9: Add new topics to multiple subjects
Add new topics to React, NodeJS, and MongoDB subjects. Ensure each subject gets at least one new topic.
```js

db.courses.updateMany({
    "name": {"$in": ["React", "NodeJS", "MongoDB"]}},
    {
        $addToSet:{
            "topics": "New Topic"
            }
})
```
or
```js
db.courses.updateMany(
  { "name": { "$in": ["React", "NodeJS", "MongoDB"] } },
  {
    $push: {
      "topics": "New Topic"
    }
  }
);

```

Task 10: Remove a topic from a subject
Remove the topic "Express" from the NodeJS subject.
```js
db.courses.updateOne(
    { "name": "NodeJS" },
    {
        $pull: {
            "topics": "Express"
            }
    }
);

```

Task 11: Query all students in a specific year
Query and return all students in year 2 or year 3.
```js
db.students.find({
    $or: [ {"year": 2},{"year": 3}]
    });
```
Task 12: Delete a student by roll number
Delete a student from the database using their roll number.
```js
db.students.deleteOne({"rollNumber": "S1234"});
```

Task 13: Delete all students from a department
Delete all students who belong to the Electrical Engineering department.
```js
db.students.deletMany({"department":"Electrical Engineering"})
```

Task 14: Retrieve all topics for a subject
Query the MongoDB subject and retrieve all topics listed for it.
```js
db.courses.findOne({"name": "React"}, {"topics": 1});
```

Task 15: Count the number of subjects in which a student is enrolled
Write a query that returns the number of subjects each student is enrolled in.
```js
db.students.aggregate([
    {
        $lookup: {
            from: "subjects",
            localField: "subjects",
            foreignField: "name",
            as: "subject"
            }
            },
            {
                $group: {
                    _id: "$_id",
                    count: { $sum: 1 }
                    }
                    }
                    ]
                    );

```