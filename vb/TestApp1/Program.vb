Imports System
Imports System.Data.SqlTypes

Module Program

    Public Structure PersonV
        Public Name As String
        Public Age As Integer
    End Structure
    Public Class PersonR
        Public Name As String
        Public Age As Integer
    End Class
    Public Sub PassStructByValue(ByVal p As PersonV)
        ' 値型を値渡し
        p.Name = "Alice"
        p.Age = 20

        p = New PersonV()
        p.Name = "Bob"
        p.Age = 25
    End Sub

    Public Sub PassStructByReference(ByRef p As PersonV)
        ' 値型を参照渡し
        p.Name = "Alice"
        p.Age = 20

        p = New PersonV()
        p.Name = "Bob"
        p.Age = 25
    End Sub

    Public Sub PassClassByValue(ByVal p As PersonR)
        ' 参照型を値渡し
        p.Name = "Alice"
        p.Age = 20

        p = New PersonR()
        p.Name = "Bob"
        p.Age = 25
    End Sub

    Public Sub PassClassByReference(ByRef p As PersonR)
        ' 参照型を参照渡し
        p.Name = "Alice"
        p.Age = 20

        p = New PersonR()
        p.Name = "Bob"
        p.Age = 25
    End Sub

    Sub Main(args As String())
        Dim p1 As PersonV
        Dim p2 As PersonR

        Console.WriteLine("CallByValue for Structure")
        p1.Name = "山田太郎"
        p1.Age = 30
        Console.WriteLine("Name = " & p1.Name & ", Age = " & p1.Age)
        PassStructByValue(p1)
        Console.WriteLine("Name = " & p1.Name & ", Age = " & p1.Age)

        Console.WriteLine("CallByReference for Structure")
        p1.Name = "山田太郎"
        p1.Age = 30
        Console.WriteLine("Name = " & p1.Name & ", Age = " & p1.Age)
        PassStructByReference(p1)
        Console.WriteLine("Name = " & p1.Name & ", Age = " & p1.Age)

        Console.WriteLine("CallByValue for Class")
        p2 = New PersonR()
        p2.Name = "山田太郎"
        p2.Age = 30
        Console.WriteLine("Name = " & p2.Name & ", Age = " & p2.Age)
        PassClassByValue(p2)
        Console.WriteLine("Name = " & p2.Name & ", Age = " & p2.Age)
        p2 = Nothing

        Console.WriteLine("CallByReference for Class")
        p2 = New PersonR()
        p2.Name = "山田太郎"
        p2.Age = 30
        Console.WriteLine("Name = " & p2.Name & ", Age = " & p2.Age)
        PassClassByReference(p2)
        Console.WriteLine("Name = " & p2.Name & ", Age = " & p2.Age)
        p2 = Nothing

    End Sub
End Module
