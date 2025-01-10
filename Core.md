# MongoDB Basics: Core Concepts

MongoDB is a flexible and powerful **NoSQL database** used for storing data in a way that’s different from traditional databases. It’s designed to work well with large amounts of unstructured or semi-structured data. Let’s explore its core concepts!

---

## 1. Data Hierarchy: Database, Collection, and Document

MongoDB uses a hierarchical data model instead of the traditional table-based model of relational databases.

- **Database**: A MongoDB instance can have many databases. Each database contains **collections**.
- **Collection**: A collection is like a table in a relational database, but it can store documents with different structures.
- **Document**: A document is similar to a row in a table. However, documents are stored in **BSON format**, which allows flexibility (unlike fixed tables).

### Example:
Let’s say you are working on a **BTech Computer Science** program. You have a database called **CodingGitaBTechDB**.

- **Database**: `CodingGitaBTechDB`
- **Collection**: `students`
- **Document**: Each student’s information is a document.

```json
{
  "name": "Arjun",
  "rollNumber": "12345",
  "department": "CSE",
  "year": 3,
  "coursesEnrolled": ["Data Structures", "DBMS", "AI"],
  "age": 21
}


```
## 2. BSON Format

MongoDB stores data in **BSON** (Binary JSON). BSON is like JSON, but it’s designed for fast storage and retrieval. It also supports more types like **Date**, **Binary**, and **ObjectId**.

### Why BSON?
- **Faster**: BSON is a binary format, so it’s faster to read, write, and query.
- **More Types**: BSON supports additional types that JSON doesn’t, like **Date** and **Binary**.

### Example:
In BSON, storing a student's **enrollment date** looks like this:

```json
{
  "name": "Krishna",
  "enrollmentDate": { "$date": "2021-08-15T00:00:00Z" }
}
```

## 3. Schema-less Nature of MongoDB

MongoDB doesn’t require a fixed schema. You don’t need to define all fields upfront. Each document in a collection can have different fields. This flexibility is helpful for evolving applications.

### Benefits of Schema-less Design:
- **Flexible**: You can add or remove fields without changing the whole structure.
- **Adaptable**: You can modify the data model over time without affecting previous data.

### Example:
Initially, a student document might only include basic details:

```json
{
  "name": "Priyesha",
  "rollNumber": "67890",
  "department": "CSE",
  "year": 2
}
```

## 4. Embedded Documents vs. References

When designing MongoDB models, you can either embed related data inside documents or use references to link documents.

- **Embedding**: Store related data within the same document. This is ideal for data that is frequently accessed together.
- **Referencing**: Store related data in separate documents and link them using ObjectIds.

### Example of Embedding:
If a student is enrolled in multiple courses, instead of having separate collections for courses, you can embed course details directly within the student document:

```json
{
  "name": "Yashvi",
  "rollNumber": "112233",
  "department": "CSE",
  "year": 1,
  "courses": [
    {
      "courseCode": "CS101",
      "courseName": "Data Structures",
      "credits": 4,
      "instructor": "Prof. Singh"
    },
    {
      "courseCode": "CS102",
      "courseName": "Database Management Systems",
      "credits": 3,
      "instructor": "Dr. Sharma"
    }
  ]
}
```

# Conclusion

MongoDB’s data model offers flexibility and scalability, making it ideal for modern applications. Key takeaways include:

- **Database > Collection > Document** hierarchy.
- MongoDB uses **BSON** for better performance and richer data types.
- It is **schema-less**, allowing easy changes and growth of the data model.
- You can choose to either **embed** or **reference** related data depending on your application needs.


